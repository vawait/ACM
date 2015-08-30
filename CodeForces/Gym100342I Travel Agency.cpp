/*
 * Author:  vawait
 * Created Time:  2015/8/30 13:30:47
 * Problem: Gym100342I Travel Agency
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
const int maxn = 21000;
int n , m , cut[maxn] , a[maxn*10] , b[maxn*10] , f[maxn];
int tim = 2 , low[maxn] , dfn[maxn];
lint ans[maxn] , sum[maxn];
vector < int > g2[maxn] , g[maxn];

int find(int t)
{
    return f[t] == t ? t : f[t] = find( f[t] );
}

void add(int x,int y)
{
    x = find( x ) , y = find( y );
    if ( x != y ) sum[x] += sum[y] , f[y] = x;
}

void dfs(int t,int v)
{
	int y , k = 1;
    lint size = 0;
	dfn[t] = low[t] = ++tim;
    ans[t] = n - 1;
    red(i,g[t].size()-1,0) {
		y = g[t][i];
		if ( y == v && k ) {
			k = 0;
			continue;
		}
		if ( !dfn[y] ) {
			dfs( y , t );
			low[t] = min( low[t] , low[y] );
            if ( low[y] >= dfn[t] && find( y ) != find( t ) ) {
                ans[t] += size * sum[find(y)];
                size += sum[find(y)];
            }
            add( y , t );
		} else low[t] = min( low[t] , dfn[y] );
	}
    ans[t] += ( n - 1 - size ) * size;
}

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    rep(i,1,n) f[i] = i , sum[i] = 1;
}

void work()
{
    rep(i,1,n) if ( !low[i] ) dfs( i , -1 );
    rep(i,1,n) printf("%I64d\n",ans[i]);
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    init();
    work();
    return 0;
}
