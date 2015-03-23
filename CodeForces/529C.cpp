/*
 * Author:  vawait
 * Created Time:  2015/3/23 12:55:33
 * Problem: CodeForces_529C
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
int N , M , K , Q , ans[maxn];
vector < int > nod[maxn] , ask[maxn];
pair < int , int > ax[maxn] , ay[maxn] , ak[maxn];

struct zkw
{
	int a[270000] , m;
	void init(int n) {
		for( m = 1; m - 2 < n; m <<= 1 );
        clr( a , 0 );
	}
	void cha(int l,int k) {
        a[l+=m] = k;
		for ( int i = l >> 1; i; i >>= 1 ) a[i] = min( a[i<<1] , a[i<<1|1] ); 
	}
	int ask(int l,int r) {
		int ans = 1e8;
		l += m - 1; r += m + 1;
		for ( ; l^r^1; l>>=1 , r>>=1 ) {
			if ( ~l&1 ) ans = min( ans , a[l^1] );
			if ( r&1 ) ans = min( ans , a[r^1] );
		}
		return ans;
	}
} T;


void init()
{
    rep(i,1,K) scanf("%d%d",&ak[i].x,&ak[i].y);
    rep(i,1,Q) scanf("%d%d%d%d",&ax[i].x,&ay[i].x,&ax[i].y,&ay[i].y);
    N = max( N , M );
    clr( ans , 0 );
}

void deal()
{
    T.init( N );
    rep(i,1,N) nod[i].clear() , ask[i].clear();
    rep(i,1,K) nod[ak[i].x].pb( ak[i].y );
    rep(i,1,Q) ask[ax[i].y].pb( i );
    rep(i,1,N) {
        red(j,nod[i].size()-1,0) T.cha( nod[i][j] , i ); 
        red(j,ask[i].size()-1,0) {
            int x = ask[i][j];
            if ( T.ask( ay[x].x , ay[x].y ) >= ax[x].x ) ans[x] = 1;
        }
    }
}

void work()
{
    deal();
    rep(i,1,K) swap( ak[i].x , ak[i].y );
    rep(i,1,Q) swap( ax[i] , ay[i] );
    deal();
    rep(i,1,Q) puts(ans[i]?"YES":"NO");
}

int main()
{
    while ( cin >> N >> M >> K >> Q ) {
        init();
        work();
    }
    return 0;
}
