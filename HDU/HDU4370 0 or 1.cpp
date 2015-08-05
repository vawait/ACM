/*
 * Author:  vawait
 * Created Time:  2015/8/5 15:12:41
 * Problem: HDU4370 0 or 1
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
int n , a[310][310] , d[400] , vis[310] , b[310][310];

void init()
{
    rep(i,1,n) 
        rep(j,1,n) scanf("%d",&a[i][j]);
    rep(i,1,n) a[i][i] = 0;
}

void spfa(int t)
{
    clr( vis , 1 );
    clr( d , 1 );
    d[t] = 0;
    queue < int > q;
    q.push( t );
    int x;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        vis[x] = 1; 
        rep(i,1,n) if ( d[x] + a[x][i] < d[i] ) {
            d[i] = d[x] + a[x][i];
            if ( vis[i] ) vis[i] = 0 , q.push( i );
        }
    }
}

void work()
{
    int ans , mx = 1e9;
    spfa( 1 );
    ans = d[n];
    rep(i,2,n-1) mx = min( mx ,  d[i] + a[i][1] );
    rep(i,1,n)
        rep(j,1,n) b[i][j] = a[j][i];
    rep(i,1,n)
        rep(j,1,n) a[i][j] = b[i][j];
    spfa( n );
    rep(i,2,n-1) ans = min( ans , mx + d[i] + a[i][n] );
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
