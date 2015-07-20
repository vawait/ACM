/*
 * Author:  vawait
 * Created Time:  2015/7/20 12:37:12
 * Problem: HDU4008 Parent and son
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
const int maxn = 201000;
int sum , n , m , num[maxn] , dep[maxn] , que[maxn] , mx1[maxn] , mx2[maxn] , fa[maxn] , f[maxn] , F[maxn];
int vis[maxn] , son1[maxn] , son2[maxn] , st[maxn][20];
vector < int > g[maxn];
vector < int > qq[maxn];

int find(int t)
{
    return F[t] == t ? t : F[t] = find( F[t] );
}

void dfs(int t)
{
    int y , x;
    que[++sum] = t;
    qq[t].pb( sum );
    num[t] = sum;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa[t] ) {
        dep[y] = dep[t] + 1;
        fa[y] = t;
        dfs( y );
        x = min( y , mx1[y] );
        if ( x < mx1[t] ) 
            mx2[t] = mx1[t] , mx1[t] = x;
        else 
            mx2[t] = min( mx2[t] , x );
        if ( y < son1[t] )
            son2[t] = son1[t] , son1[t] = y;
        else 
            son2[t] = min( son2[t] , y );
        que[++sum] = t;
        qq[t].pb( sum );
    }
}

void dfs(int t,int d)
{
    int y;
    f[t] = d;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa[t] )
        dfs( y , min( min( t , d ) , mx1[t] == mx1[y] ? mx2[t] : mx1[t] ) );
}

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    clr( fa , 0 ); clr( vis , 0 );
    rep(i,1,n) g[i].clear() , qq[i].clear() ,  F[i] = i , mx1[i] = mx2[i] = son1[i] = son2[i] = n + 1;
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    sum = 0;
    fa[1] = n + 1;
    dfs( 1 );
    dfs( 1 , n + 1 );
    
    rep(i,1,sum) st[i][0] = i;
    rep(j,1,20)
        rep(i,1,sum+1-(1<<j)) {
            int x = st[i][j-1] , y = st[i+(1<<(j-1))][j-1];
            if ( dep[que[x]] < dep[que[y]] )
                st[i][j] = x;
            else
                st[i][j] = y;
        }
}

int LCA(int l,int r)
{
    if ( l > r ) swap( l , r );
    if ( l == r ) return l;
    int t = log( r - l + 1.0 ) / log( 2.0 );
    int x = st[l][t] , y = st[r-(1<<t)+1][t];
    return dep[que[x]] < dep[que[y]] ? x : y;
}

int find2(int y,int x)
{
    int l = 0 , r = qq[y].size() - 1 , k;
    while ( l < r ) {
        k = ( l + r + 1 ) >> 1;
        if ( qq[y][k] > x ) r = k - 1; else l = k;
    }
    return qq[y][l];
}

void work()
{
    int x , y;
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        int ans1 , ans2 , a = LCA( num[x] , num[y] ) , lca = que[a];
        if ( x == y ) {
            ans1 = min( son1[x] , fa[x] );
            ans2 = min( mx1[x] , f[x] );
        } else if ( y != lca ) {
            ans1 = son1[y];
            ans2 = mx1[y];
        } else {
            a = que[LCA( num[x] , find2( y , num[x] ) + 1 )];
            ans1 = min( fa[y] , son1[y] == a ? son2[y] : son1[y] );
            ans2 = min( f[y] , mx1[y] == min( mx1[a] , a ) ? mx2[y] : mx1[y] );
        }
        if ( ans1 > n ) 
            puts("no answers!");
        else
            printf("%d %d\n",ans1,ans2);
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
