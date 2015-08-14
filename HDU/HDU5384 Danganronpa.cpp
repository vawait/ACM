/*
 * Author:  vawait
 * Created Time:  2015/8/13 13:05:06
 * Problem: HDU5384 Danganronpa
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
const int maxn = 420000;
int N , M , n , beg[maxn] , Len[maxn] , num[maxn];
lint ans[maxn] , b[maxn];

struct suffix
{
	
	#define F(x) ((x)/3+((x)%3==1?0:tb))
	#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2) 
	#define Suffix 401010
	int rank[Suffix] , sa[Suffix*3] , h[Suffix] , r[Suffix*3];
	int wa[Suffix] , wb[Suffix] , wv[Suffix] , ws[Suffix] , f[401010][20];
	char s[Suffix*3];
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
	}
	void st() {
		rep(i,1,n+1) f[i][0] = h[i];
		rep(j,1,19) 
			red(i,n+1-(1<<j)+1,1) f[i][j] = min( f[i][j-1] , f[i+(1<<(j-1))][j-1] );
	}
	int lcp(int l,int r) {
		if ( l > r ) swap( l , r );
		l ++;
		int x = log( r - l + 1 ) / log( 2.0 );
		return min( f[l][x] , f[r-(1<<x)+1][x] );
	}
	void init() {
        int len;
        n = 0;
        scanf("%d%d",&N,&M);
        rep(i,1,N+M) {
            scanf("%s",s);
            len = strlen( s );
            beg[i] = n + 1;
            Len[i] = len;
            rep(j,0,len-1) {
                r[n++] = s[j] - 'a' + 1;
                num[n] = i;
            }
            r[n++] = 28;
            num[n] = 0;
        }
		r[n] = r[n+1] = 0;
		dc3( r , sa , n + 1 , 30 ); 
		calc();
		st();
	}
} s;

void init()
{
    s.init();
    rep(i,0,n+10) b[i] = ans[i] = 0;
}

void work()
{
    int l , r , k , p;
    clr( b , 0 ); clr( ans , 0 );
    rep(i,N+1,M+N) {
        p = s.rank[beg[i]];
        r = p;
        l = 1;
        while ( l < r ) {
            k = ( l + r ) >> 1;
            if ( s.lcp( k , p ) >= Len[i] ) r = k; else l = k + 1;
        }
        b[l] ++;
        l = p , r = n + 1;
        while ( l < r ) {
            k = ( l + r + 1 ) >> 1;
            if ( s.lcp( p , k ) >= Len[i] ) l = k; else r = k - 1;
        }
        b[r+1] --;
    }
    b[0] = 0;
    rep(i,1,n) {
        b[i] += b[i-1];
        ans[num[s.sa[i]]] += b[i];
    }
    rep(i,1,N) printf("%I64d\n",ans[i]);
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
