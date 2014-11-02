/*
 * Author:  vawait
 * Created Time:  2014/11/2 22:46:13
 * Problem: SPOJ_XXXXXXXX
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
const int maxn = 50020;
int sum , n , m , a[maxn] , b[maxn] , last[maxn];
std :: set < int > st[150020];  
std :: set < int > :: iterator it;
std :: map < int , int > h;

struct BitTree
{
	struct node {
		int l , r;
        lint v;
	} T[150020*32];
	int sz , root[maxn] , Rt[maxn];
	void build(int &i,int l,int r,int x,int v) {
	   T[++sz] = T[i]; i = sz;
	   T[i].v += v;
	   int m = ( l + r ) >> 1;
	   if ( l == r ) return;
	   if ( x <= m ) build( T[i].l , l , m , x , v ); else build( T[i].r , m + 1 , r , x , v );
	}
	void ins(int &i,int l,int r,int &x,int &v) {
		if ( !i ) T[++sz] = T[i] , i = sz;
		T[i].v += v;
		if ( l == r ) return;
		int m = ( l + r ) >> 1;
		if ( x <= m ) ins( T[i].l , l , m , x , v ); else ins( T[i].r , m + 1 , r , x , v );
	}
	void BITins(int t,int x,int v) {
		for ( ; t <= maxn; t += t & -t ) ins( root[t] , 1 , maxn , x , v );
	}
    lint find(int t,int L,int l,int r) {
        if ( !t || l >= L ) return T[t].v;
        int m = ( l + r ) >> 1;
        lint sum = find( T[t].r , L , m + 1 , r );
        if ( L <= m ) sum += find( T[t].l , L , l , m );
        return sum;
	}
	lint ask(int t,int L) {
        lint ans = find( Rt[t] , L , 1 , maxn );
		for ( ; t; t -= t & -t ) ans += find( root[t] , L , 1 , maxn );
		return ans;
	}
	void init() {
        int x;
		sz = 0;
		rep(i,1,n) {
            x = Rt[i-1];
            if ( last[a[i]] ) build( x , 1 , maxn , last[a[i]] , -b[i] );
            build( Rt[i] = x , 1 , maxn , i , b[i] );
            last[a[i]] = i;
            st[a[i]].insert( i );
        }
	}
} T;

int id(int y)
{
    if ( h.count( y ) ) return h[y];
    h[y] = ++ sum;
    st[sum].insert( 0 );
    st[sum].insert( n + 1 );
    return sum;
}

void init()
{
    sum = 0;
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&b[i]) , a[i] = id( b[i] );
    T.init();
    scanf("%d",&m);
}

void work()
{
    int x , y , p , pre , nex;
    char c[3];
    while ( m -- ) {
        scanf("%s%d%d",c,&x,&y);
        if ( c[0] == 'U' ) {
            it = --st[a[x]].find( x );
            pre = *it; 
            it ++; nex = *( ++it );
            if ( pre > 0 ) T.BITins( x , pre , b[x] );
            T.BITins( x , x , -b[x] );
            if ( nex <= n ) {
                T.BITins( nex , x , b[x] );
                if ( pre > 0 ) T.BITins( nex , pre , -b[x] );
            }
            st[a[x]].erase( x );
            
            b[x] = y; a[x] = id( y );
            st[a[x]].insert( x );
            it = --st[a[x]].find( x );
            pre = *it; 
            it ++; nex = *( ++it );
            if ( pre ) T.BITins( x , pre , -y );
            T.BITins( x , x , y );
            if ( nex <= n ) {
                T.BITins( nex , x , -y );
                if ( pre ) T.BITins( nex , pre , y );
            }
        } else {
            printf("%lld\n",T.ask( y , x ));
        }
    }
}

int main()
{
    init();
    work();
    return 0;
}
