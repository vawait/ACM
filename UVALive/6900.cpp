/*
 * Author:  Twist Of Fate
 * Created Time:  2015年03月19日 星期四 15时27分29秒
 * File Name: UVALive_6900
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define db pop_back
typedef long long lint;
const int maxn = 21000;
int n , askq[maxn] , asksum;
lint ans = 0 , qq , C;

struct zkw
{
	lint a[101000];
	int m;
	void init(int n) {
		for( m = 1; m - 2 < n; m += m );
        clr( a , 0 );
	}
	void cha(int l,lint k) {
        l += m;
        if ( a[l] > k ) return;
        a[l] = k;
		for ( int i = l >> 1; i; i >>= 1 ) a[i] = max( a[i<<1] , a[i<<1|1] ); 
	}
	lint ask(int l,int r) {
		lint ans = 0;
		l += m - 1; r += m + 1;
		for ( ; l^r^1; l>>=1 , r>>=1 ) {
			if ( ~l&1 ) ans = max( ans , a[l^1] );
			if ( r&1 ) ans = max( ans , a[r^1] );
		}
		return ans;
	}
} T;

struct nodd
{
	lint ss , sum , f[maxn];
	int t , k , mx[maxn] , a[maxn] , s[maxn];
	bool v[maxn];
	struct node {
		int y , d , n , ben;
	} b[maxn<<1];
	void add(int x,int y,int d,int ben) {
		b[++t].y = y; b[t].d = d;
		b[t].ben = ben; b[t].n = a[x]; a[x] = t;
	}

	void fdfs(int t,int fa) {
		s[t] = 1; mx[t] = 0;
		for( int p = a[t]; p; p = b[p].n ) if ( b[p].y != fa && v[b[p].y] ) {
			fdfs( b[p].y , t );
			s[t] += s[b[p].y];
			mx[t] = max( mx[t] , s[b[p].y] );
		}
	}
	void froot(int t,int m,int &root) {
		mx[t] = max( mx[t] , m - s[t] );
		for ( int p = a[t]; p; p = b[p].n ) if ( v[b[p].y] && s[t] > s[b[p].y] ) froot( b[p].y , m , root );
		if ( mx[t] < mx[root] ) root = t;
	}

	void dfs(int t,int fa) {
        if ( k ) {
            int x = asknum( C - ss );
            if ( x ) {
                lint y = T.ask( 1 , x ) - qq + sum;
                if ( y > ans ) ans = y;
            }
        } else {
            T.cha( asknum( ss ) , sum + qq );
        }
		for ( int p = a[t]; p; p = b[p].n ) if ( v[b[p].y] && b[p].y != fa ) {
            sum += b[p].ben;
			ss += b[p].d;
			dfs( b[p].y , t );
			ss -= b[p].d;
            sum -= b[p].ben;
		}
	}
	void init() {
		int x , y , dd , ben;
		t = 1;
        scanf("%d",&n);
		rep(i,1,n) v[i] = 1 , a[i] = 0;
		rep(i,2,n) {
			scanf("%d%d%d%d",&x,&y,&dd,&ben);
			add( x , y , dd , ben );
			add( y , x , dd , ben );
		}
	}

    void dealdfs(int t,int fa,int sum) {
        askq[++asksum] = sum;
        for ( int p = a[t]; p; p = b[p].n) if ( v[b[p].y] && b[p].y != fa ) dealdfs( b[p].y , t , sum + b[p].d );
    }
    void deal(int t) {
        asksum = 0;
        dealdfs( t , 0 , 0 );
        sort( askq + 1 , askq + 1 + asksum );
    }
    int asknum(int sum) {
        int l = 1 , r = asksum , k;
        if ( askq[1] > sum ) return 0;
        while ( l < r ) {
            k = ( l + r + 1 ) >> 1;
            if ( askq[k] <= sum ) l = k; else r = k - 1;
        }
        return l;
    }

	void ask() {
		rep(i,1,n) while ( v[i] ) {
			fdfs( i , 0 );
			if ( s[i] == 1 ) break;
			int x = i;
			froot( i , s[i] , x );
            deal( x );
			v[x] = 0;
			qq += 20000000000LL;
			T.cha( 1 , qq );
			for ( int p = a[x]; p; p = b[p].n ) if ( v[b[p].y] ) {
				sum = b[p].ben; k = 1; ss = b[p].d;
				dfs( b[p].y , x );
				sum = b[p].ben; k = 0; ss = b[p].d;
				dfs( b[p].y , x );
			}
		}
	}
} Tree;


void init()
{
    ans = 0;
    Tree.init();
    T.init( n );
    cin >> C;
}

void work()
{
    Tree.ask();
    cout << ans << endl;
}

int main()
{
    int t;
    for ( cin >> t; t; t -- ) {
        init();
        work();
    }
    return 0;
}
