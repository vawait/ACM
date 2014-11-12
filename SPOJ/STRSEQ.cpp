/*
 * Author:  vawait
 * Created Time:  2014/11/12 20:58:14
 * Problem: SPOJ_STRSEQ
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
const int maxn = 1100;
int n , m , t , S = 0 , T , ans;
int a[maxn] , d[maxn] , pre[maxn] , f[maxn] , v[maxn];

struct nodd
{
	int y , d , f , n;
} b[110000];

void add(int x,int y,int d,int f)
{
	b[++t].y = y; b[t].d = d; b[t].f = f;
	b[t].n = a[x]; a[x] = t;
	b[++t].y = x; b[t].d = 0; b[t].f = -f;
	b[t].n = a[y]; a[y] = t;
}

bool spfa()
{
	queue < int > q;
	int x , y;
	q.push( S );
	clr( d , 1 );
	d[S] = 0;
	while ( !q.empty() ) {
		x = q.front(); q.pop();
		v[x] = 0;
		for ( int p = a[x]; p; p = b[p].n ) if ( b[p].d && b[p].f + d[x] < d[y=b[p].y] ) {
			d[y] = d[x] + b[p].f;
			pre[y] = x; f[y] = p;
			if ( !v[y] ) v[y] = 1 , q.push( y );
		}
	}
	if ( d[T] >= d[T+1] ) return 0;
    int mx = 2e9;
	for ( x = T; x != S; x = pre[x] ) mx = min( mx , b[f[x]].d  );
	for ( x = T; x != S; x = pre[x] ) b[f[x]].d -= mx , b[f[x]^1].d += mx;
	ans += d[T] * mx;
	return 1;
}

void init()
{
    int mm = 1e9 , x , y , c;
    t = 1; clr( a , 0 );
    T = n + 1;
    add( 0 , 1 , mm , 0 );
    rep(i,1,n) {
        scanf("%d",&x);
        add( i , i + 1 , mm - x , 0 );
    }
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&c);
        add( x , y + 1 , mm , c );
    }
}

void work()
{
    ans = 0;
    while ( spfa() );
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
