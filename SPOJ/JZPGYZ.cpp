/*
 * Author:  vawait
 * Created Time:  2014/11/3 14:54:35
 * Problem: SPOJ_JZPGYZ
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
const int maxn = 120000;
int n , m , len , p[maxn] , pre[maxn] , ans[maxn];
char c[maxn<<1] , s[maxn];
vector < pair < int , int > > q[maxn];

struct suffix
{
	int n , rank[maxn] , sa[maxn];
	int X[maxn<<1] , Y[maxn<<1] , sum[maxn];
	bool cmp(int *r,int a,int b,int l) {
		return ( r[a] == r[b] && r[a+l] == r[b+l] );
	}
	void calc() {
		int l , p , *x = X , *y = Y , m = 128;
		rep(i,0,m) sum[i] = 0;
		rep(i,1,n) sum[ x[i] = c[i] ] ++;
		rep(i,1,m) sum[i] += sum[i-1];
		red(i,n,1) sa[ sum[ x[i] ]-- ] = i;
		for ( l = 1 , p = 1 ; l <= n ; m = p , l *= 2 ) {
			p = 0;
			rep(i,n-l+1,n) y[++p] = i;
			rep(i,1,n) if ( sa[i] > l ) y[++p] = sa[i] - l;
			rep(i,0,m) sum[i] = 0;
			rep(i,1,n) sum[ x[y[i]] ] ++;
			rep(i,1,m) sum[i] += sum[i-1];
			red(i,n,1) sa[ sum[ x[y[i]] ]-- ] = y[i];
			swap( x , y );
			x[sa[1]] = 1; p = 2;
			rep(i,2,n)
				x[ sa[i] ] = cmp(y,sa[i-1],sa[i],l) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
	}
	void init() {
		n = len;
        calc();
	}
} sa;

struct bit
{
    int t[maxn+10];
    void add(int x,int y) {
        for ( ; x <= maxn; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
    int ask(int l,int r) {
        return sum( r ) - sum( l - 1 );
    }
} T;

void init()
{
    int l;
    scanf("%d%d",&n,&m);
    len = 0;
    rep(i,1,n) {
        scanf("%s",s+1);
        l = strlen( s + 1 );
        rep(j,1,l) p[++len] = i , c[len] = s[j];
        p[++len] = 0;
    }
    sa.init();
}

int cmp(int r,int len)
{
    rep(i,1,len) if ( s[i] != c[r++] ) return (int)s[i] - c[r-1];
    return 0;
}

void build()
{
    int Len , l , r , k , R;
    rep(i,1,m) {
        scanf("%s",s+1);
        Len = strlen( s + 1 );
        l = 1; r = len;
        while ( l < r ) {
            k = ( l + r + 1 ) >> 1;
            if ( cmp( sa.sa[k] , Len ) >= 0 ) l = k; else r = k - 1;
        }
        if ( cmp( sa.sa[l] , Len ) ) continue;
        R = l; l = 1;
        while ( l < r ) {
            k = ( l + r ) >> 1;
            if ( cmp( sa.sa[k] , Len ) <= 0 ) r = k; else l = k + 1;
        }
        q[R].pb( mp( i , l ) );
    }
}

void work()
{
    int x , id;
    build();
    rep(i,1,len) {
        x = p[sa.sa[i]];
        if ( pre[x] ) T.add( pre[x] , -1 );
        T.add( i , 1 );
        pre[x] = i;
        red(j,q[i].size()-1,0) {
            id = q[i][j].x;
            ans[id] = T.ask( q[i][j].y , i );
        }
    }
    rep(i,1,m) printf("%d\n",ans[i]);
}

int main()
{
    init();
    work();
    return 0;
}
