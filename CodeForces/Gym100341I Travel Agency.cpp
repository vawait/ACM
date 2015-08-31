/*
 * Author:  vawait
 * Created Time:  2015/8/31 13:47:25
 * Problem: Gym100341I Travel Agency
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x) * (x))
typedef long long lint;
const int maxn = 401000;
int num = 0 , n , b[4] , x[maxn] , y[maxn] , sum[maxn] , ty[maxn];
int p[maxn][4];
vector < pair < int , int > > g[maxn];
vector < int > a[maxn];
map < int , int > h[4];

void add(int x,int y,int p)
{
    for ( ; x <= sum[p]; x += x & ( -x ) ) a[p][x] += y;
}

int SUM(int x,int p)
{
    int s = 0;
    for ( ; x; x -= x & (-x) ) s += a[p][x];
    return s;
}

void del(int i)
{
    rep(j,0,3) {
        int d = x[i];
        if ( j == 1 ) d = y[i];
        if ( j == 2 ) d = x[i] + y[i];
        if ( j == 3 ) d = x[i] - y[i];
        b[j] = h[j][d];
        if ( b[j] ) add( p[i][j] , -1 , b[j] );
    }
}

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&x[i],&y[i]);
    rep(i,0,n) {
        rep(j,0,3) {
            int d = x[i];
            if ( j == 1 ) d = y[i];
            if ( j == 2 ) d = x[i] + y[i];
            if ( j == 3 ) d = x[i] - y[i];
            if ( !h[j].count( d ) ) {
                h[j][d] = ++num;
                ty[num] = j;
                g[num].pb( mp( -2e9 , 0 ) );
                a[num].pb( 0 );
            }
            b[j] = h[j][d];
        }
        rep(j,0,3) {
            int d = b[j] , k = x[i];
            if ( !j ) k = y[i];
            g[d].pb( mp( k , i ) );
            a[d].pb( 0 );
        }
    }
    rep(i,1,num) {
        sort( g[i].begin() , g[i].end() );
        sum[i] = g[i].size() - 1;
        rep(j,1,sum[i]) add( j , 1 , i );
        rep(j,1,sum[i]) p[g[i][j].y][ty[i]] = j;
    }
}

int ask(int x1,int y1,int x2,int y2)
{
    if ( x1 == x2 ) return 0;
    if ( y1 == y2 ) return 1;
    if ( x1 + y1 == x2 + y2 ) return 2;
    if ( x1 - y1 == x2 - y2 ) return 3;
    return 10;
}

void work()
{
    int ans = 0 , xx = 0 , yy = 0;
    del( 0 );
    rep(i,1,n) {
        del( i );
        int d = ask( xx , yy , x[i] , y[i] ) , ty = xx - yy;
        if ( d > 3 ) break;
        if ( d == 0 ) ty = xx;
        if ( d == 1 ) ty = yy;
        if ( d == 2 ) ty = xx + yy;
        int l = p[i-1][d] , r = p[i][d];
        d = h[d][ty];
        if ( l > r ) swap( l , r );
        if ( l ) l --;
        if ( SUM( r , d ) - SUM( l , d ) ) break;
        ans ++;
        xx = x[i] , yy = y[i];
    }
    cout << ans << endl;
}

int main()
{
    freopen("queen2.in","r",stdin);
    freopen("queen2.out","w",stdout);
    init();
    work();
    return 0;
}
