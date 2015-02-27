/*
 * Author:  vawait
 * Created Time:  2015/2/26 15:05:31
 * Problem: CodeForces_387E
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
const int maxn = 1001000;
int n , m , s , p[maxn] , b[maxn] , v[maxn] , L[maxn] , R[maxn];
pair < int , int > a[maxn] , mx[maxn];

struct bit
{
    int t[1001000];
    void add(int x,int y) {
        for ( ; x <= 1000000; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
} T;

void init()
{
    clr( v , 0 );
    clr( T.t , 0 );
    rep(i,1,n) scanf("%d",&p[i]);
    rep(i,1,m) scanf("%d",&b[i]);
    s = 1;
    rep(i,1,n) if ( s <= m && p[i] == b[s] ) v[i] = 1 , s ++;
    s = 0;
    rep(i,1,n) if ( !v[i] ) a[++s] = mp( p[i] , i );
    m = n - m;
    if ( m ) sort( a + 1 , a + m + 1 ); 
}

void deal(int i,int &ans)
{    
    int l = 1 , r = s , k;
    while ( l < r ) {
        k = ( l + r + 1 ) >> 1;
        if ( mx[k].x < p[i] ) l = k; else r = k - 1;
    }
    ans = mx[l].y;
    if ( v[i] ) {
        while ( s && mx[s].x > p[i] ) s --;
        mx[++s] = mp( p[i] , i );
    }
}

void work()
{
    lint ans = 0;
    mx[s=1] = mp( 0 , 0 );
    rep(i,1,n) deal( i , L[i] );
    mx[s=1] = mp( 0 , n + 1 );
    red(i,n,1) deal( i , R[i] );
    
    rep(i,1,n) T.add( i , 1 );
    rep(i,1,m) {
        int x = a[i].y;
        ans += T.sum( R[x] - 1 ) - T.sum( L[x] );
        T.add( x , -1 );
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
