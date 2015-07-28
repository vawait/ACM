/*
 * Author:  vawait
 * Created Time:  2015/7/28 13:46:17
 * Problem: HDU5325 Crazy Bobo
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long lint;
const int maxn = 501000;
int n , ans , w[maxn] , fu[maxn] , f[maxn];
vector < int > g[maxn];

void init()
{
    int x , y;
    rep(i,1,n) g[i].clear() , f[i] = 0;
    rep(i,1,n) scanf("%d",&w[i]);
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    ans = 0;
}

void dfs(int t,int fa)
{
    int y;
    fu[t] = 1;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa ) {
        dfs( y , t );
        if ( w[t] < w[y] ) fu[t] += fu[y];
    }
}

void dfs2(int t,int fa)
{
    int y;
    ans = max( ans , fu[t] + f[t] );
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa ) {
        if ( w[t] > w[y] ) f[y] += f[t] + fu[t];
        dfs2( y , t );
    }
}

void work()
{
    dfs( 1 , 0 );
    dfs2( 1 , 0 );
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
