/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月08日 星期六 13时47分21秒
 * File Name: HDU_4008
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define db pop_back
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long lint;
const int maxn = 400010;
int n , m , sum , dfn[maxn] , fa[maxn] , p[maxn];
int st[maxn][20] , fdown[maxn] , fson[maxn][2] , f[maxn][2];
vector < int > g[maxn];

void add(int t)
{
    st[++sum][0] = t;
    p[t] = sum;
}

void dfs_son(int t)
{
    int y;
    fdown[t] = n + 1;
    red(i,g[t].size()-1,0) if( ( y = g[t][i] ) != fa[t] ) {
        fa[y] = t;
        dfn[y] = dfn[t] + 1;
        add( t );
        dfs_son( y );
        fdown[t] = min( fdown[t] , min( y , fdown[y] ) );
    }
    add( t );
}

void dfs_des(int t,int mx)
{
    int y;
    f[t][0] = f[t][1] = n + 1;
    if ( mx < f[t][0] ) f[t][1] = f[t][0] , f[t][0] = mx;
    else if ( mx < f[t][1] ) f[t][1] = mx;
    red(i,g[t].size()-1,0) if( ( y = g[t][i] ) != fa[t] ) {
        mx = min( fdown[y] , y );
        if ( mx < f[t][0] ) f[t][1] = f[t][0] , f[t][0] = mx;
        else if ( mx < f[t][1] ) f[t][1] = mx;
    }
    red(i,g[t].size()-1,0) if( ( y = g[t][i] ) != fa[t] )
        dfs_des( y , min( t , f[t][0] == y || f[t][0] == fdown[y] ? f[t][1] : f[t][0] ) );
}

int mx(int x,int y)
{
    return dfn[x] < dfn[y] ? x : y;
}

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    rep(i,1,n) g[i].clear();
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    dfn[1] = fa[1] = 0;
    sum = 0;
    dfs_son( 1 );
    dfs_des( 1 , n + 1 );
    rep(j,1,19)
        red(i,sum-(1<<j)+1,1) st[i][j] = mx( st[i][j-1] , st[i+(1<<(j-1))][j-1] );
}

int lca(int x,int y)
{
    x = p[x]; y = p[y];
    if ( x > y ) swap( x , y );
    int t = log( y - x + 1.0 ) / log( 2.0 );
    return mx( st[x][t] , st[y-(1<<t)+1][t] );
}

void work()
{
    int x , y , ans1 , ans2;
    rep(i,1,n) {
        fson[i][0] = fson[i][1] = n + 1;
        red(j,g[i].size()-1,0) {
            y = g[i][j];
            if ( y < fson[i][0] ) fson[i][1] = fson[i][0] , fson[i][0] = y;
            else if ( y < fson[i][1] ) fson[i][1] = y;
        }
    }
    while ( m -- ) {
        scanf("%d%d",&x,&y);
        if ( lca( x , y ) == y ) {
            ans1 = ( fson[y][0] <= n && dfn[lca( fson[y][0] , x )] <= dfn[y] ) ? fson[y][0] : fson[y][1];
            ans2 = ( f[y][0] <= n && dfn[lca( f[y][0] , x )] <= dfn[y] ) ? f[y][0] : f[y][1];
        } else {
            ans1 = ( fson[y][0] <= n && fa[fson[y][0]] == y ) ? fson[y][0] : fson[y][1];
            ans2 = fdown[y];
        }
        if ( ans1 > n ) puts("no answers!"); else printf("%d %d\n",ans1,ans2);
    }
    puts("");
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
