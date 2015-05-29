/*
 * Author:  vawait
 * Created Time:  2015/5/29 11:01:00
 * Problem: Codeforces547E Mike and Friends
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
const int maxn = 201000;
int n , q , Begin[maxn] , fa[maxn<<1] , len[maxn];
char s[maxn];

struct suffix
{
	#define F(x) ((x)/3+((x)%3==1?0:tb))
	#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2) 
	#define Suffix 401000
	int n , rank[Suffix] , sa[Suffix*3] , h[Suffix] , r[Suffix*3];
	int wa[Suffix] , wb[Suffix] , wv[Suffix] , ws[Suffix];
	int f[Suffix][20];
	int c0(int *r,int a,int b) {
		return r[a] == r[b] && r[a+1] == r[b+1] && r[a+2] == r[b+2];
	} 
	int c12(int k,int *r,int a,int b) {
		if( k == 2 ) return r[a] < r[b] || ( r[a] == r[b] && c12(1,r,a+1,b+1) ); 
		else return r[a] < r[b] || ( r[a] == r[b] && wv[a+1] < wv[b+1] );
	} 
	void sort(int *r,int *a,int *b,int n,int m) { 
		rep(i,0,n-1) wv[i] = r[a[i]]; 
		rep(i,0,m-1) ws[i] = 0; 
		rep(i,0,n-1) ws[wv[i]] ++; 
		rep(i,1,m-1) ws[i] += ws[i-1]; 
		red(i,n-1,0) b[--ws[wv[i]]] = a[i]; 
	}
	void dc3(int *r,int *sa,int n,int m)
	{
		int i , j , *rn = r + n , *san = sa + n , ta = 0 , tb = ( n + 1 ) / 3 , tbc = 0 , p; 
		r[n] = r[n+1] = 0; 
		rep(i,0,n-1) if( i % 3 ) wa[tbc++] = i; 
		sort(r+2,wa,wb,tbc,m); 
		sort(r+1,wb,wa,tbc,m); 
		sort(r,wa,wb,tbc,m); 
		for ( p = 1 , rn[F(wb[0])] = 0 , i = 1; i < tbc; i++) 
			rn[F(wb[i])] = c0(r,wb[i-1],wb[i]) ? p - 1 : p ++; 
		if ( p < tbc ) dc3(rn,san,tbc,p); 
		else rep(i,0,tbc-1) san[rn[i]] = i;
		rep(i,0,tbc-1) if( san[i] < tb ) wb[ta++] = san[i] * 3; 
		if( n % 3 == 1) wb[ta++] = n - 1; 
		sort(r,wb,wa,ta,m); 
		rep(i,0,tbc-1) wv[wb[i] = G(san[i])] = i; 
		for ( i = 0 , j = 0 , p = 0; i < ta && j < tbc; p++) 
			sa[p] = c12(wb[j]%3,r,wa[i],wb[j]) ? wa[i++] : wb[j++]; 
		for( ; i < ta; p++) sa[p] = wa[i++]; 
		for( ; j < tbc; p++) sa[p] = wb[j++]; 
	}
	void calc() {
		int p = 0;
		red(i,n+1,1) sa[i] = sa[i-1] + 1;
		rep(i,1,n+1) rank[sa[i]] = i;
		rep(i,1,n+1) {
			if ( rank[i] == 1 ) continue;
			while ( r[i+p-1] == r[sa[rank[i]-1]+p-1] ) p ++;
			h[rank[i]] = p;
			if ( p ) p --;
		}
		rep(i,1,n+1) f[i][0] = h[i];
		rep(j,1,19) 
			red(i,n+1-(1<<j)+1,1) f[i][j] = min( f[i][j-1] , f[i+(1<<(j-1))][j-1] );
	}
	int lcp(int l,int r) {
        if ( l == r ) return 1e9;
		l ++;
		int x = log( r - l + 1 ) / log( 2.0 );
		return min( f[l][x] , f[r-(1<<x)+1][x] );
	}
	void init() {
		r[n] = 0;
		dc3( r , sa , n + 1 , 40 ); 
		calc();
	}
} sa;

struct ZXTree
{
	struct node {
		int l , r , v;
	} T[maxn*30];
	int sz , root[maxn*2];
	void ins(int &i,int l,int r,int x) {
	   int m = ( l + r ) >> 1;
	   T[++sz] = T[i]; i = sz;
	   T[i].v ++;
	   if ( l == r ) return;
	   if ( x <= m ) ins( T[i].l , l , m , x ); else ins ( T[i].r , m + 1 , r , x );
	}
	int ask(int x,int y,int l,int r,int L,int R) {
        if ( L <= l && r <= R ) return T[y].v - T[x].v;
        int mid = ( l + r ) >> 1 , ans = 0;
        if ( L <= mid ) ans += ask( T[x].l , T[y].l , l , mid , L , R );
        if ( R > mid ) ans += ask( T[x].r , T[y].r , mid + 1 , r , L , R );
        return ans;
	}
	void init() {
		root[0] = sz = 0;
        rep(i,1,sa.n+1) {
            int x = fa[sa.sa[i]];
            if ( x ) 
                ins( root[i] = root[i-1] , 1 , n , x );
            else
                root[i] = root[i-1];
        }
	}
} T;

void init()
{
    scanf("%d%d",&n,&q);
    sa.n = -1;
    rep(i,1,n) {
        scanf("%s",s);
        len[i] = strlen( s );
        sa.r[++sa.n] = 30;
        Begin[i] = sa.n + 2;
        rep(j,0,len[i]-1) {
            sa.r[++sa.n] = s[j] - 'a' + 1;
            fa[sa.n+1] = i;
        }
    }
    sa.n ++;
    sa.init();
    T.init();
}

void work()
{
    int x , y , k , L;
    while ( q -- ) {
        scanf("%d%d%d",&x,&y,&k);
        int p = sa.rank[Begin[k]] , l = 1 , r = p , mid;
        while ( l < r ) {
            mid = ( l + r ) >> 1;
            if ( sa.lcp( mid , p ) >= len[k] ) r = mid; else l = mid + 1;
        }
        L = l;
        l = p , r = sa.n + 1;
        while ( l < r ) {
            mid = ( l + r + 1 ) >> 1;
            if ( sa.lcp( p , mid ) >= len[k] ) l = mid; else r = mid - 1;
        }
        printf("%d\n",T.ask(T.root[L-1],T.root[r],1,n,x,y));
    }
}

int main()
{
    init();
    work();
    return 0;
}
