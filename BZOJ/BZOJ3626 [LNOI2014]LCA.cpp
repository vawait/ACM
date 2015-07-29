/*
 * Author:  vawait
 * Created Time:  2015/7/29 14:58:02
 * Problem: BZOJ3626 [LNOI2014]LCA
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
const int maxn = 101000;
const int mod = 201314;
int n , m , sum , dep[maxn] , num[maxn] ; 
int ds[maxn] , sz[maxn] , son[maxn] , fa[maxn] , top[maxn];
lint ans[maxn];
vector < int > g[maxn];
vector < pair < int , int > > ask[maxn];

struct zkw
{
	lint a[maxn<<2] , b[maxn<<2];
	int p , m , h;
	void init(int n) {
		for( m = 1 , h = 0; m - 2 < n; m += m , h ++ );
	}
	void down(int t) {
		red(i,h,1) if ( b[ p = t >> i ] ) {
			b[p] >>= 1;
			a[p<<1] += b[p]; a[p<<1|1] += b[p];
			b[p<<1] += b[p]; b[p<<1|1] += b[p];
			b[p] = 0;
		}
	}
	void cha(int l,int r,lint k) {
		int ll , rr;
		l += m-1; r += m+1;
		ll = l >> 1; rr = r >> 1;
		down(l); down(r);
		for ( ; l^r^1; l>>=1,r>>=1,k<<=1 ) {
			if ( ~l&1 ) a[l^1] += k , b[l^1] += k;
			if ( r&1 ) a[r^1] += k , b[r^1] += k;
		}
		for ( int i = ll; i; i >>= 1 ) a[i] = a[i<<1] + a[i<<1|1]; 
		for ( int i = rr; i; i >>= 1 ) a[i] = a[i<<1] + a[i<<1|1];
	}
	lint ask(int l,int r) {
		lint ans = 0;
		l += m-1; r += m+1;
		down(l); down(r);
		for ( ; l^r^1; l>>=1 , r>>=1 ) {
			if ( ~l&1 ) ans += a[l^1];
			if ( r&1 ) ans += a[r^1];
		}
		return ans;
	}
} T;

void dfs1(int t) {
	sz[t] = 1; son[t] = 0;
	red(i,g[t].size()-1,0) {
        fa[g[t][i]] = t;
        dep[g[t][i]] = dep[t] + 1;
		dfs1( g[t][i] );
		sz[t] += sz[g[t][i]];
		if ( sz[g[t][i]] > sz[son[t]] ) son[t] = g[t][i];
	}
}

void dfs2(int t,int tp) {
	num[t] = ++sum; top[t] = tp;
	if ( son[t] ) dfs2( son[t] , tp );
	red(i,g[t].size()-1,0) if ( g[t][i] != son[t] ) dfs2( g[t][i] , g[t][i] );
}

void init()
{
    int x , y , z;
    rep(i,2,n) {
        scanf("%d",&x);
        g[x+1].pb( i );
    }
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&z);
        x ++; y ++; z ++;
        ask[x-1].pb( mp( z , -i ) ); 
        ask[y].pb( mp( z , i ) ); 
    }
    dep[1] = 1;
    dfs1( 1 );
    dfs2( 1 , 1 );
    T.init( n );
}

void work()
{
    rep(t,1,n) {
        for ( int x = t; x ; x = fa[top[x]] )
            T.cha( num[top[x]] , num[x] , 1 );
        red(i,ask[t].size()-1,0) {
            lint sum = 0 , y = ask[t][i].y;
            for ( int x = ask[t][i].x ; x ; x = fa[top[x]] )
                sum += T.ask( num[top[x]] , num[x] );
            if ( y < 0 ) ans[-y] -= sum; else ans[y] += sum;
        }
    }
    rep(i,1,m) printf("%d\n",int(ans[i]%mod));
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
