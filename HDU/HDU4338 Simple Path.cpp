/*
 * Author:  vawait
 * Created Time:  2015/8/1 15:51:01
 * Problem: HDU4338 Simple Path
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long lint;
const int maxn = 401000;
int n , m , f[maxn] , fa[maxn] , dep[maxn] , sum[maxn] , col[maxn];
int sz[maxn] , flag[maxn];
int tt , top , num , que[maxn] , d[maxn] , low[maxn] , Fa[maxn][20];
vector < int > g1[maxn] , g[maxn];

int find(int t)
{
    return f[t] == t ? t : f[t] = find( f[t] );
}

void dfs_cut(int t,int fa)
{
    int son = 0 , y , vis = 0;
    low[t] = d[t] = ++tt;
    red(i,g1[t].size()-1,0) {
        y = g1[t][i];
        if ( y == fa && !vis ) {
            vis = 1;
            continue;
        }
        if ( !low[y] ) {
            son ++;
            dfs_cut( y , t );
            low[t] = min( low[t] , low[y] );
            if ( ( !fa && son > 1 ) || ( fa && low[y] >= d[t] ) ) flag[t] = 1;
        } else if ( fa != y )
            low[t] = min( low[t] , d[y] );
    }
} 

void dfs_build(int t,int f)
{
    d[t] = 1;
    fa[t] = f;
    sz[t] = sum[t] + sz[f];
    dep[t] = dep[f] + 1;
    red(i,g[t].size()-1,0) if ( g[t][i] != f )
        dfs_build( g[t][i] , t );
}

void dfs_tarjan(int t,int fa)
{
    low[t] = d[t] = ++tt;
    que[++top] = t;
    int y , v = 0 , tmp;
    red(i,g1[t].size()-1,0) {
        y = g1[t][i];
        if( y == fa && !v ) {
            v = 1;
            continue;
        }
        if ( !d[y] ) {
            dfs_tarjan( y , t );
            if ( low[y] < low[t] ) low[t] = low[y];
            if ( low[y] >= d[t] ) {
                sum[++num] = 1 ; col[t] = num ; g[num].clear();
                do{
                    tmp = que[top--] , ++sum[num] , col[tmp] = num;
                    if ( flag[tmp] ) g[tmp].pb( num ) , g[num].pb( tmp );
                } while( tmp != y );
                if ( flag[t] ) g[t].pb( num ) , g[num].pb( t );
            }
        }else if( d[y] < low[t]) low[t] = d[y];
    }
}


void init()
{
    int x , y , p , q;
    rep(i,0,n) f[i] = i , sum[i] = 1 , fa[i] = -1;
    rep(i,0,n) g1[i].clear() , g[i].clear();
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        x ++; y ++;
        g1[x].pb( y );
        g1[y].pb( x );
        f[find(x)] = find( y );
    }
    
    tt = 1;
    clr( low , 0 ); clr( flag , 0 );
    rep(i,1,n) if ( !low[i] ) dfs_cut( i , 0 );
    top = 0;
    num = n;
    clr( d , 0 );
    rep(i,1,n) if ( !d[i] ) dfs_tarjan( i , 0 );
    clr( d , 0 );
    
    top = 1;
    rep(i,1,num) if ( !d[i] ) {
        sz[i] = sum[i];
        dep[i] = 1;
        dfs_build( i , 0 );
    }
    rep(i,1,num) Fa[i][0] = fa[i];
    rep(j,1,19)
        rep(i,1,num) Fa[i][j] = Fa[Fa[i][j-1]][j-1];
}

int lca(int x,int y)
{
    if ( dep[x] < dep[y] ) swap( x , y );
    red(i,19,0) if ( dep[Fa[x][i]] >= dep[y] ) x = Fa[x][i];
    if ( x == y ) return x;
    red(i,19,0) if ( Fa[x][i] != Fa[y][i] ) x = Fa[x][i] , y = Fa[y][i];
    return Fa[x][0]; 
}

void work()
{
    int Q , x , y , p , q , LCA , ans;
    scanf("%d",&Q);
    while ( Q -- ) {
        scanf("%d%d",&x,&y);
        x ++; y ++;
        if ( x == y ) {
            printf("%d\n",n-1);
        } else if ( find( x ) != find( y ) ) {
            printf("%d\n",n);
        } else {
            p = flag[x] ? x : col[x];
            q = flag[y] ? y : col[y];
            LCA = lca( p , q );
            ans = n - ( sz[p] + sz[q] - 2 * sz[LCA] + sum[LCA] );
            ans += dep[p] + dep[q] - 2 * dep[LCA];
            printf("%d\n",ans);
        }
    }
    puts("");
}

int main()
{
    int t = 0;
    while ( cin >> n >> m ) {
        printf("Case #%d:\n",++t);
        init();
        work();
    }
    return 0;
}
