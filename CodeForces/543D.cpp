/*
 * Author:  vawait
 * Created Time:  2015/5/11 21:10:27
 * Problem: CodeForces_543D
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
const lint mm = 1e9 + 7;
const int maxn = 201000;
lint n , f[maxn] , fa[maxn];
vector < int > g[maxn] , l[maxn] , r[maxn];

void init()
{
    int x;
    rep(i,1,n) g[i].clear() , l[i].clear() , r[i].clear();
    rep(i,2,n) {
        scanf("%d",&x);
        g[i].pb( x );
        g[x].pb( i );
        l[i].pb( 1 );
        r[i].pb( 1 );
        l[x].pb( 1 );
        r[x].pb( 1 );
    }
}

void dfs1(int t)
{
    f[t] = 1;
    red(i,g[t].size()-1,0) if ( g[t][i] != fa[t] ) {
        fa[g[t][i]] = t;
        dfs1( g[t][i] );
        ( f[t] *= f[g[t][i]] + 1 ) %= mm;
    }
}

void dfs2(int t,lint ans)
{
    ( f[t] *= ++ans ) %= mm;
    int mx = g[t].size() - 1;
    red(i,mx,0) r[t][i] = ( i < mx ? r[t][i+1] : 1 ) * ( g[t][i] == fa[t] ? 1 : f[g[t][i]] + 1 ) % mm;
    rep(i,0,mx) l[t][i] = ( i ? l[t][i-1] : 1 ) * (  g[t][i] == fa[t] ? 1 : f[g[t][i]] + 1 ) % mm;
    rep(i,0,mx) if ( g[t][i] != fa[t] ) {
        lint sum = ans;
        if ( i ) ( sum *= l[t][i-1] ) %= mm;
        if ( i < mx ) ( sum *= r[t][i+1] ) %= mm;
        dfs2( g[t][i] , sum );
    }
}

void work()
{
    dfs1( 1 );
    dfs2( 1 , 0 );
    rep(i,1,n) printf("%I64d%c",f[i],i==n?'\n':' ');
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
