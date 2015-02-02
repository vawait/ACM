/*
 * Author:  vawait
 * Created Time:  2015/2/3 1:29:17
 * Problem: CodeForces_512C
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
int v[4000] , p[40000];
int n , a[40000] , vh[40000] , h[40000] , N , S , t;
vector < int > g[4000];
int sum , q[400][400];

struct nodd
{
    int x , y , d , n;
} b[200000];

void add(int x,int y,int d)
{
    b[++t].y = y; b[t].d = d;
    b[t].n = a[x]; a[x] = t; b[t].x = x;
    b[++t].y = x; b[t].d = 0;
    b[t].n = a[y]; a[y] = t; b[t].x = y;
}

int sap(int t,int d)
{
    int minh = 450 , max = d , x , y;
    if ( t == N ) return d;
    for ( int p = a[t]; p; p = b[p].n ) if ( b[p].d ) {
        y = b[p].y;
        if ( h[y] + 1 == h[t] ) {
            x = sap( y , max > b[p].d ? b[p].d : max );
            b[p].d -= x; b[ p ^ 1 ].d += x;
            max -= x; 
            if ( !max || h[S] > 410 ) return d - max;
        }
        if ( h[y] < minh ) minh = h[y];
    }
    if ( max == d ) {
        if ( !( -- vh[h[t]] ) ) h[S] = 450;
        vh[ h[t] = minh + 1 ] ++;
    }
    return d - max;
}

void init()
{
    p[1] = 1;
    rep(i,2,20000) if ( !p[i] ) {
        for ( int j = i + i; j <= 20000; j += i ) p[j] = 1;
    }
    sum = 0;
    rep(i,1,n) g[i].clear();
    rep(i,1,n) scanf("%d",&v[i]);
    t = 1;
    clr( a , 0 );
    S = 0;
    N = n + 1;
    rep(i,1,n) if ( v[i] & 1 ) {
        add( 0 , i , 2 ); 
        rep(j,1,n) if ( !( v[j] & 1 ) && !p[v[i]+v[j]] ) add( i , j , 1 );
    } else {
        add( i , N , 2 );
    }
    clr( h , 0 ); 
    clr( vh , 0 ); vh[0] = N + 2;
}

void dfs(int t)
{
    p[t] = 1;
    q[sum][++q[sum][0]] = t;
    red(i,g[t].size()-1,0) {
        int y = g[t][i];
        if ( !p[y] ) dfs( y );
    }
}

void work()
{
    int ans = 0;
    while ( h[0] <= N ) ans += sap( 0 , 100000 );
    if ( ( n & 1 ) || ans != n ) {
        puts("Impossible");
        return ;
    }
    
    sum = 0;
    rep(i,2,t) if ( b[i].x <= n && b[i].x >= 1 && ( v[b[i].x] & 1 ) && !b[i].d ) {
        int x = b[i].x , y = b[i].y;
        g[x].pb( y );
        g[y].pb( x );
    }
    clr( p , 0 );
    rep(i,1,n) if ( !p[i] ) {
        sum ++;
        q[sum][0] = 0;
        dfs( i );
    }
    
    printf("%d\n",sum);
    rep(i,1,sum)
        rep(j,0,q[i][0]) printf("%d%c",q[i][j],j==q[i][0]?'\n':' ');
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
