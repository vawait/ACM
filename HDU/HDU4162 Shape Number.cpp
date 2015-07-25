/*
 * Author:  vawait
 * Created Time:  2015/7/25 14:44:19
 * Problem: HDU4162 Shape Number
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
#define Suffix 600010
typedef long long lint;
int n;
char c[301000];

struct suffix
{
	#define F(x) ((x)/3+((x)%3==1?0:tb))
	#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2) 
	int rank[Suffix] , sa[Suffix*3] , h[Suffix] , r[Suffix*3];
	int wa[Suffix] , wb[Suffix] , wv[Suffix] , ws[Suffix];
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
    void init() {
        n = strlen(c);
        rep(i,0,n-2) r[i] = ( c[i+1] - c[i] + 8 ) % 8;
        r[n-1] = ( c[0] - c[n-1] + 8 ) % 8;
        rep(i,0,n-1) r[i+n] = r[i];
        n *= 2;
        r[n] = 0;
        dc3( r , sa , n + 1 , 30 ); 
        calc();
        int p;
        rep(i,1,n) if ( sa[i] >= 1 && sa[i] <= n / 2 ) {
            p = sa[i] - 1;
            break;
        }
        rep(i,p,p+n/2-1) printf("%d",r[i]);
        puts("");
    }
} s;

void init()
{
    s.init();
}

void work()
{
}

int main()
{
    while ( scanf("%s",c) != EOF ) {
        init();
        work();
    }
    return 0;
}
