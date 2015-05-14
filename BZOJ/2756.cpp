/*
 * Author:  vawait
 * Created Time:  2015/5/14 11:46:47
 * Problem: BZOJ_2756
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
#define num( x , y ) ( ( x - 1 ) * m + y )
typedef long long lint;
const int maxn = 1700;
int a[maxn+10] , vh[maxn+10] , h[maxn+10] , N = 1670 , S = 0 , t;
int n , m , mx , f[50][50];
int dx[] = { 0 , 0 , -1 , 1 };
int dy[] = { 1 , -1 , 0 , 0 };
lint ans;

struct nodd
{
    int y , n;
    lint d;
} b[maxn*20];

void add(int x,int y,lint d)
{
    b[++t].y = y; b[t].d = d;
    b[t].n = a[x]; a[x] = t;
    b[++t].y = x; b[t].d = 0;
    b[t].n = a[y]; a[y] = t;
}

lint sap(int t,lint d)
{
    int minh = maxn + 1 , y;
    lint max = d , x;
    if ( t == N ) return d;
    for ( int p = a[t]; p; p = b[p].n ) if ( b[p].d ) {
        y = b[p].y;
        if ( h[y] + 1 == h[t] ) {
            x = sap( y , max > b[p].d ? b[p].d : max );
            b[p].d -= x; b[ p ^ 1 ].d += x;
            max -= x; 
            if ( !max || h[S] > maxn ) return d - max;
        }
        if ( h[y] < minh ) minh = h[y];
    }
    if ( max == d ) {
        if ( !( -- vh[h[t]] ) ) h[0] = maxn + 1;
        vh[ h[t] = minh + 1 ] ++;
    }
    return d - max;
}

void init()
{
    mx = 0;
    scanf("%d%d",&n,&m);
    rep(i,1,n)
        rep(j,1,m) scanf("%d",&f[i][j]) , mx = max( mx , f[i][j] );
}

bool ok(lint x)
{
    lint sum1 = 0 , sum2 = 0;
    t = 1;
    clr( a , 0 ); clr( h , 0 );
    clr( vh , 0 ); vh[0] = n * m + 2;
    rep(i,1,n)
        rep(j,1,m) if ( ( i + j ) & 1 ) 
            sum1 += x - f[i][j];
        else 
            sum2 += x - f[i][j];
    if ( sum1 != sum2 ) return 0;
    ans = sum1;
    rep(i,1,n)
        rep(j,1,m) if ( ( i + j ) & 1 ) {
            add( 0 , num( i , j ) , x - f[i][j] );
            rep(k,0,3) {
                int x = dx[k] + i , y = dy[k] + j;
                if ( x > 0 && x <= n && y > 0 && y <= m )
                    add( num( i , j ) , num( x , y ) , 1e16 );
            }
        } else {
            add( num( i , j ) , N , x - f[i][j] );
        }
    while ( h[0] <= maxn ) sum1 -= sap( 0 , 1LL<<40 );
    return sum1 == 0;
}

void work()
{
    if ( ( n * m ) & 1 ) {
        lint sum = 0;
        rep(i,1,n)
            rep(j,1,m) if ( ( i + j ) & 1 )
                sum -= f[i][j];
            else
                sum += f[i][j];
        if ( sum < mx || !ok( sum ) )
            puts("-1");
        else 
            cout << ans << endl;
    } else {
        lint l = mx , r = max( mx + 100 , 2 * mx ) , k;
        while ( l < r ) {
            k = ( l + r ) >> 1;
            if ( ok( k ) ) r = k; else l = k + 1;
        }
        if ( ok ( l ) ) 
            cout << ans << endl;
        else
            puts("-1");
    }
}

int main()
{
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
