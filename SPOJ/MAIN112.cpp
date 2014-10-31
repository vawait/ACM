/*
 * Author:  vawait
 * Created Time:  2014/10/31 13:59:11
 * File Name: SPOJ_MAIN112.cpp
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
int n , m , a[20] , c[20] , f[1<<16][16] , d[1<<16];

void init()
{
    scanf("%d",&n);
    n --;
    rep(i,0,n) scanf("%d",&a[i]);
    rep(i,0,n) scanf("%d",&c[i]);
    clr( f , 1 );
    m = ( 1 << ( n + 1 ) ) - 1;
    rep(i,0,n) f[1<<i][i] = 0;
    rep(i,0,m) d[i] = d[i>>1] + ( i & 1 );
}

void work()
{
    int ans = 10000000;
    rep(i,1,m)
        rep(j,0,n) if ( f[i][j] <= 10000000 ) {
            rep(k,0,n) if ( ( ( 1 << k ) & i ) == 0 ) 
                f[i|(1<<k)][k] = min( f[i|(1<<k)][k] , f[i][j] + abs( a[j] - a[k] ) * c[d[i]] );
        }
    rep(i,0,n) ans = min( ans , f[m][i] );
    printf("%d\n",ans);
}

int main()
{
    int t;
    for ( cin >> t; t; t -- ) {
        init();
        work();
    }
    return 0;
}
