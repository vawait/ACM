/*
 * Author:  vawait
 * Created Time:  2015/6/20 19:21:03
 * Problem: HDU5274 Dylans loves tree
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
#define ls ( t << 1 )
#define rs ( t << 1 | 1 )
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long lint;
const int maxn = 101000;
int sum , dep[maxn] , num[maxn]; 
int sz[maxn] , son[maxn] , fa[maxn] , top[maxn] , q[maxn];
int n , m , A[maxn];
vector < int > g[maxn];

struct nodd
{
    int a[maxn<<3];
    void build(int t,int l,int r) {
        if ( l == r ) {
            a[t] = A[q[l]];
            return;
        }
        int mid = ( l + r ) >> 1;
        build( ls , l , mid );
        build( rs , mid + 1 , r );
        a[t] = a[ls] ^ a[rs];
    }
    void cha(int t,int l,int r,int al,int ar) {
        if ( al == l && r == al ) {
            a[t] = ar;
            return;
        }
        int mid = ( l + r ) >> 1;
        if ( al <= mid ) cha( ls , l , mid , al , ar );
        else cha( rs , mid + 1 , r , al , ar );
        a[t] = a[ls] ^ a[rs];
    }
    int ask(int t,int l,int r,int al,int ar) {
        if ( al <= l && r <= ar )
            return a[t];
        int mid = ( l + r ) >> 1 , ans = 0;
        if ( al <= mid ) ans ^= ask( ls , l , mid , al , ar );
        if ( ar > mid ) ans ^= ask( rs , mid + 1 , r , al , ar );
        return ans;
    }
} T;

void dfs1(int t) {
	sz[t] = 1; son[t] = 0; dep[t] = dep[fa[t]] + 1;
	red(i,g[t].size()-1,0) if ( g[t][i] != fa[t] ) {
		fa[g[t][i]] = t;
		dfs1( g[t][i] );
		sz[t] += sz[g[t][i]];
		if ( sz[g[t][i]] > sz[son[t]] ) son[t] = g[t][i];
	}
}

void dfs2(int t,int tp) 
{
	num[t] = ++sum; top[t] = tp;
    q[sum] = t;
	if ( son[t] ) dfs2( son[t] , tp );
	red(i,g[t].size()-1,0) if ( g[t][i] != fa[t] && g[t][i] != son[t] ) dfs2( g[t][i] , g[t][i] );
}

int ask(int l,int r) 
{
	int t1 = top[l] , t2 = top[r] , ans = 0;
	while ( t1 != t2 ) {
		if ( dep[t1] < dep[t2] ) swap( t1 , t2 ) , swap( l ,r );
		ans ^= T.ask( 1 , 1 , n , num[t1] , num[l] );
		l = fa[t1] ; t1 = top[l];
	}
	if ( dep[l] > dep[r] ) swap( l , r );
    ans ^= T.ask( 1 , 1 , n , num[l] , num[r] );
	return ans;
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
    rep(i,1,n) scanf("%d",&A[i]) , A[i] ++;
    
    sum = 0;
	dfs1( 1 ); 
	dfs2( 1 , 1 );
    T.build( 1 , 1 , n );
}

void work()
{
    int ty , x , y;
    while ( m -- ) {
        scanf("%d%d%d",&ty,&x,&y);
        if ( ty == 0 ) {
            T.cha( 1 , 1 , n , num[x] , y + 1 );
        } else {
            printf("%d\n",ask(x,y)-1);
        }
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
