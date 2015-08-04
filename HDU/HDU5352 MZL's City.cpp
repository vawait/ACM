/*
 * Author:  vawait
 * Created Time:  2015/8/4 16:23:31
 * Problem: HDU5352 MZL's City
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
int n , m , mx , num;
int g[210][210] , sum[1000] , fp[1000];
int ans , t , S = 0 , T = 1002 , a[maxn] , d[maxn] , pre[maxn] , f[maxn] , v[maxn];

struct nodd
{
	int y , d , f , n;
} b[210000];

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
    mx = 1;
	//for ( x = T; x != S; x = pre[x] ) mx = min( mx , b[f[x]].d  );
	for ( x = T; x != S; x = pre[x] ) b[f[x]].d -= mx , b[f[x]^1].d += mx;
	ans += d[T] * mx;
	return 1;
}


int find(int t)
{
    return f[t] == t ? t : f[t] = find( f[t] );
}

void calc()
{
    int x;
    num ++;
    rep(i,1,n) f[i] = i;
    rep(i,1,n)
        rep(j,1,n) if ( g[i][j] ) f[find(i)] = find( j );
    scanf("%d",&x);
    fp[num] = t + 1;
    add( S , num , mx , 1000 - num );
    rep(i,1,n) if ( find( i ) == find( x ) ) add( num , i , 1 , 0 );
}

void init()
{
    int  ty , p , x , y;
    t = 1; clr( a , 0 );
    t = 1;
    clr( a , 0 );
    clr( g , 0 );
    scanf("%d%d%d",&n,&m,&mx);
    rep(i,1,n) add( i , T , 1 , 0 );
    num = n;
    rep(i,1,m) {
        scanf("%d",&ty);
        if ( ty == 1 ) {
            calc();
        } else if ( ty == 2 ) {
            scanf("%d%d",&x,&y);
            g[x][y] = g[y][x] = 1;
        } else {
            scanf("%d",&p);
            while ( p -- ) {
                scanf("%d%d",&x,&y);
                g[x][y] = g[y][x] = 0;
            }
        }
    }
}

void work()
{
    ans = 0;
    while ( spfa() ) spfa();
    int s = 0;
    for ( int i = a[S]; i; i = b[i].n ) sum[b[i].y] = b[i^1].d;
    rep(i,n+1,num) s += sum[i];
    printf("%d\n",s);
    rep(i,n+1,num) printf("%d%c",sum[i],i==num?'\n':' ');
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
