/*
 * Author:  vawait
 * Created Time:  2014/11/23 22:29:49
 * Problem: CodeForces_490F
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
int n , ans = 1 , r[6010] , f[6010];
vector < int > g[6010];

void init()
{
    int x , y;
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&r[i]);
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    clr( f , 1 );
    f[0] = 0;
}

int ask(int t)
{
    int l = 1 , r = n , k;
    while ( l < r ) {
        k = ( l + r ) >> 1;
        if ( f[k] >= t ) r = k; else l = k + 1;
    }
    return l;
}

void dfs(int t,int fa)
{
    int x = ask( r[t] ) , pre = f[x];
    ans = max( ans , x );
    f[x] = r[t];
    red(i,g[t].size()-1,0) if ( g[t][i] != fa )
        dfs( g[t][i] , t );
    f[x] = pre;
}

void work()
{
    rep(i,1,n) dfs( i , 0 );
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
