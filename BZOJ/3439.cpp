/*
 * Author:  vawait
 * Created Time:  2015/5/15 15:22:30
 * Problem: BZOJ_3439
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
int sum = 0 , n , a[maxn] , L[maxn] , R[maxn] , F[maxn];
int trie[maxn][26];
vector < int > g[maxn];
char s[maxn];

struct ZXTree
{
	struct node {
		int l , r , v;
	} T[maxn*25];
	int sz , root[maxn];
	void ins(int &i,int l,int r,int x) {
	   int m = ( l + r ) >> 1;
	   T[++sz] = T[i]; i = sz;
	   T[i].v ++;
	   if ( l == r ) return;
	   if ( x <= m ) ins( T[i].l , l , m , x ); else ins ( T[i].r , m + 1 , r , x );
	}
	int ask(int x,int y,int k) {
		int l = 1 , r = n;
		x = root[x-1] , y = root[y];
        if ( T[y].v - T[x].v < k ) return -1;
		while ( l != r ) {
			int m = ( l + r ) >> 1 , t = T[T[y].l].v - T[T[x].l].v;
			if ( k <= t )
				x = T[x].l , y = T[y].l , r = m;
			else 
				x = T[x].r , y = T[y].r , l = m + 1 , k -= t;
		}
		return l;
	}
	void init() {
		root[0] = sz = 0;
		rep(i,1,n) ins( root[i] = root[i-1] , 1 , n , a[i] );
	}
} T;

void dfs(int t)
{
    L[t] = sum + 1;
    red(i,g[t].size()-1,0) a[++sum] = g[t][i];
    rep(i,0,25) if ( trie[t][i] ) dfs( trie[t][i] );
    R[t] = sum;
}

void init()
{
    int len , x , p;
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%s",s+1);
        len = strlen( s + 1 );
        p = 0;
        red(j,len,1) {
            x = s[j] - 'a';
            if ( !trie[p][x] ) trie[p][x] = ++sum;
            p = trie[p][x];
        }
        F[i] = p;
        g[p].pb( i );
    }
    sum = 0;
    dfs( 0 );
}

void work()
{
    int x , y;
    T.init();
    rep(i,1,n) {
        scanf("%d",&x);
        y = F[i];
        printf("%d\n",T.ask( L[y] , R[y] , x ));
    }
}

int main()
{
    init();
    work();
    return 0;
}
