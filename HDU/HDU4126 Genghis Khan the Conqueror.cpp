/*
 * Author:  vawait
 * Created Time:  2015/7/24 14:43:51
 * Problem: HDU4126 Genghis Khan the Conqueror
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
const int maxn = 3010;
int n , m , a[maxn][maxn] , f[maxn][maxn];
int pre[maxn] , use[maxn] , d[maxn];
lint sum;
vector < int > g[maxn];
char c;

void scan(int &x)
{
    while(c=getchar(),c<'0'||c>'9');x=c-'0';
    while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';
}

void prim()
{
    sum = 0;
    rep(i,1,n) d[i] = a[1][i] , use[i] = 0 , pre[i] = 1;
    use[1] = 1;
    rep(k,2,n) {
        int mx = 1e9 , p;
        rep(i,1,n) if ( !use[i] && d[i] < mx ) mx = d[p=i];
        g[p].pb( pre[p] ); g[pre[p]].pb( p );
        sum += d[p];
        use[p] = 1;
        rep(i,1,n) if ( !use[i] && a[p][i] < d[i] ) d[i] = a[p][i] , pre[i] = p;
    }
}

void init()
{
    int mx = 1e9 , x , y , d;
    rep(i,1,n) g[i].clear();
    rep(i,1,n)
        rep(j,1,n) a[i][j] = f[i][j] = mx;
    rep(i,1,m) {
        scan( x ); scan( y ); scan( d );
        x ++; y ++;
        a[x][y] = a[y][x] = d;
    }
    prim();
}

int dfs(int root,int t,int fa)
{
    int ans = 1e9 , y , x;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa ) {
        x = dfs( root , y , t );
        ans = min( ans , x );
        if ( x < f[t][y] ) f[t][y] = f[y][t] = x;
    }
    if ( fa != root ) ans = min( ans , a[root][t] );
    return ans;
}

void work()
{
    int Q , x , y , d;
    lint ans = 0;
    scan( Q );
    rep(i,1,n) dfs( i , i , -1 );
    rep(i,1,Q) {
        scan( x ) , scan( y ) , scan( d );
        x ++; y ++;
        if ( pre[x] != y && pre[y] != x )
            ans += sum;
        else
            ans += sum - a[x][y] + min( d , f[x][y] );
    }
    printf("%.4f\n",(double)ans/Q);
}

int main()
{
    while ( scanf("%d%d",&n,&m) && n ) {
        init();
        work();
    }
    return 0;
}
