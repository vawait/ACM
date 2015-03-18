/*
 * Author:  vawait
 * Created Time:  2015/3/18 18:08:40
 * Problem: CodeForces_528B
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
int n , m , b[maxn*2];
pair < int , int > a[maxn];
map < int , int > h;

struct zkw
{
	lint a[1200000];
	void init(int n) {
		for( m = 1 ; m - 2 < n; m += m );
        clr( a , 0 );
	}
	void change(int l,int k) {
        l += m;
        a[l] = k;
		for ( l >>= 1; l; l >>= 1 ) a[l] = max( a[l<<1] , a[l<<1|1] );
	}
	int ask(int l,int r) {
		lint ans = 0;
		l += m - 1; r += m + 1;
		for ( ; l^r^1; l>>=1 , r>>=1 ) {
			if ( ~l&1 ) ans = max( ans , a[l^1] );
			if ( r&1 ) ans = max( ans , a[r^1] );
		}
		return ans;
	}
} Tree;

void init()
{
    h.clear();
    rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    sort( a + 1 , a + n + 1 );
    
    int m = 0 , s = 1;
    rep(i,1,n) b[++m] = a[i].x - a[i].y , b[++m] = a[i].x + a[i].y;
    sort( b + 1 , b + m + 1 );
    rep(i,1,m) if ( !h.count( b[i] ) ) h[b[i]] = ++s;
    
    Tree.init( s );
}

void work()
{
    int ans = 0 , x;
    rep(i,1,n) {
        x = Tree.ask( 1 , h[a[i].x-a[i].y] ) + 1;
        Tree.change( h[a[i].x+a[i].y] , x );
        ans = max( ans , x );
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
