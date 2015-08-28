/*
 * Author:  vawait
 * Created Time:  2015/8/27 13:15:42
 * Problem: Gym100338C Important Roads
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
int n , m , a[maxn] , b[maxn] , c[maxn] , vis[maxn]; 
int tim , sum , q[maxn];
lint d[maxn] , d2[maxn] , low[maxn];
vector < pair < int , int > > g[maxn];

void init()
{
    rep(i,1,n) g[i].clear();
    rep(i,1,m) {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        g[a[i]].pb( mp( b[i] , c[i] ) );
        g[b[i]].pb( mp( a[i] , c[i] ) );
    }
}

void spfa(int s)
{
    priority_queue < pair < int , int > > q;
    int x , y;
    lint mx = 1e12;
    rep(i,1,n) d[i] = mx;
    d[s] = 0;
    q.push( mp( -d[s] , s ) );
    while ( !q.empty() ) {
        x = q.top().y; mx = -q.top().x;
        q.pop();
        if ( mx != d[x] ) continue;
        red(i,g[x].size()-1,0) if ( d[x] + g[x][i].y < d[y=g[x][i].x] ) {
            d[y] = d[x] + g[x][i].y;
            q.push( mp( -d[y] , y ) );
        }
    }
}

void dfs(int t,int v)
{
	int y , k = 1;
	d[t] = low[t] = ++tim;
    red(i,g[t].size()-1,0) {
		y = g[t][i].x;
		if ( y == v && k ) {
			k = 0;
			continue;
		}
		if ( !d[y] ) {
			dfs( y , t );
			low[t] = min( low[t] , low[y] );
			if ( low[y] > d[t] ) q[++sum] = g[t][i].y;
		} else low[t] = min( low[t] , d[y] );
	}
}

void work()
{
    spfa( 1 );
    rep(i,1,n) d2[i] = d[i];
    spfa( n );
    rep(i,1,n) g[i].clear();
    rep(i,1,m) {
        int x = a[i] , y = b[i];
        rep(j,1,2) {
            if ( d2[x] + c[i] + d[y] == d[1] ) {
                g[x].pb( mp( y , i ) );
                g[y].pb( mp( x , i ) );
            }
            swap( x , y );
        }
    }
    sum = 0;
    tim = 2;
    rep(i,1,n) d[i] = low[i] = 0;
    rep(i,1,n) if ( !d[i] ) dfs( i , -1 );
    printf("%d\n",sum);
    rep(i,1,sum) printf("%d%c",q[i],i==sum?'\n':' ');
}

int main()
{
    freopen("important.in","r",stdin);
    freopen("important.out","w",stdout);
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
