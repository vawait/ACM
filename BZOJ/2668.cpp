/*
 * Author:  vawait
 * Created Time:  2015/5/21 11:47:23
 * Problem: BZOJ_2668
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
#define num( x , y ) ( ( x - 1 ) * m + y )
typedef long long lint;
const int maxn = 1000;
int n , m , ans = 0 , t = 1 , S = 0 , T = 902 , sum1 = 0 , sum2 = 0;
int a[maxn] , d[maxn] , pre[maxn] , f[maxn] , v[maxn];
int dx[] = { 0 , 0 , -1 , 1 , 1 , 1 , -1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 , -1 , 1 , 1 , -1 };
char Begin[40][40] , End[40][40] , Mx[40][40];

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
	for ( x = T; x != S; x = pre[x] ) b[f[x]].d --, b[f[x]^1].d ++;
	ans += d[T];
	return 1;
}

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",Begin[i]+1);
    rep(i,1,n) scanf("%s",End[i]+1);
    rep(i,1,n) scanf("%s",Mx[i]+1);
    rep(i,1,n)
        rep(j,1,m) {
            int x = Mx[i][j] - '0';
            x += ( Begin[i][j] == '1' ) + ( End[i][j] == '1' );
            add( num( i , j ) , num( i , j ) + n * m , x / 2 , 1 );
            
            if ( Begin[i][j] == '1' )
                add( S , num( i , j ) , 1 , 0 ) , sum1 ++;
            if ( End[i][j] == '1' ) 
                add( num( i , j ) + n * m , T , 1 , 0 ) , sum2 ++;
            rep(k,0,7) {
                int x = i + dx[k] , y = j + dy[k];
                if ( x >= 1 && x <= n && y >= 1 && y <= m )
                    add( num( i , j ) + n * m , num( x , y ) , 1e6 , 0 );
            }
        }
}

void work()
{
    if ( sum1 != sum2 ) {
        puts("-1");
        return;
    }
    rep(i,1,sum1) if ( !spfa() ) {
        puts("-1");
        return;
    }
    printf("%d\n",ans-sum1);
}

int main()
{
    init();
    work();
    return 0;
}
