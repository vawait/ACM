/*
 * Author:  vawait
 * Created Time:  2015/5/6 15:23:41
 * Problem: HDU_5221
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
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long lint;
const int maxn = 101000;
int sum , son[maxn] , fa[maxn] , sz[maxn] , dep[maxn] , top[maxn];
int n , ans , val[maxn] , L[maxn] , R[maxn] , num[maxn];
vector < int > g[maxn];

struct nodd
{
    int a[maxn*20] , al , ar , as , lazy[maxn*20];
    void build(int t,int l,int r) {
        lazy[t] = -1;
        if ( l == r ) {
            a[t] = val[num[l]];
            return ;
        }
        int mid = ( l + r ) >> 1;
        build( t << 1 , l , mid );
        build( t << 1 | 1 , mid + 1 , r );
        a[t] = a[t<<1] + a[t<<1|1];
    }
    void down(int t) {
        lazy[t<<1] = lazy[t<<1|1] = a[t<<1] = a[t<<1|1] = lazy[t];
        lazy[t] = -1;
    }
    void up(int t,int l,int r) {
        if ( l >= al && r <= ar ) {
            lazy[t] = as;
            ans += a[t] - as;
            a[t] = as;
            return;
        }
        if ( lazy[t] > -1 ) down( t );
        int mid = ( l + r ) >> 1;
        if ( al <= mid ) up( t << 1 , l , mid );
        if ( ar > mid ) up( t << 1 | 1 , mid + 1 , r );
        a[t] = a[t<<1] + a[t<<1|1];
    }
    void cha(int all,int arr,int ass) {
        al = all;
        ar = arr;
        as = ass;
        up( 1 , 1 , sum );
    }
}T;

void dfs1(int t)
{
    sz[t] = 1; son[t] = 0;
	red(i,g[t].size()-1,0) if ( g[t][i] != fa[t] ) {
		fa[g[t][i]] = t;
        dep[g[t][i]] = dep[t] + 1;
		dfs1( g[t][i] );
		sz[t] += sz[g[t][i]];
		if ( sz[g[t][i]] > sz[son[t]] ) son[t] = g[t][i];
	}
}

void dfs2(int t,int tp) {
	L[t] = ++sum; top[t] = tp; num[sum] = t;
	if ( son[t] ) dfs2( son[t] , tp );
	red(i,g[t].size()-1,0) if ( g[t][i] != fa[t] && g[t][i] != son[t] ) 
        dfs2( g[t][i] , g[t][i] );
    R[t] = sum;
}

void init()
{
    int x , y;
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&val[i]);
    rep(i,0,n) g[i].clear();
    g[0].pb( 1 );
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    ans = sum = 0;
    dfs1( 0 );
    dfs2( 0 , -1 );
    T.build( 1 , 1 , sum );
}

void ask(int l,int r) 
{
    while ( top[l] != top[r] ) {
        if ( dep[top[l]] < dep[top[r]] ) swap( l , r );
        T.cha( L[top[l]] , L[l] , 0 );
        l = fa[top[l]];
    }
    if ( dep[l] > dep[r] ) swap( l , r );
    T.cha( L[l] , L[r] , 0 );
}

void work()
{
    int q , ty , x , y;
    scanf("%d",&q);
    while ( q -- ) {
        scanf("%d",&ty);
        if ( ty == 1 ) {
            scanf("%d%d",&x,&y);
            ask( x , y );
        } else if ( ty == 3 ) {
            scanf("%d",&x);
            T.cha( L[x] , R[x] , 0 );
        } else {
            scanf("%d",&x);
            T.cha( L[x] , L[x] , val[x] );
        }
        printf("%d\n",ans);
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
