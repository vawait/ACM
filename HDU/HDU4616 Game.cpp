/*
 * Author:  vawait
 * Created Time:  2015/9/14 12:43:01
 * Problem: HDU4616 Game
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
const int maxn = 51000;
int n , m , val[maxn] , tra[maxn];
lint f[maxn][5][2] , ff[5] , ans;
vector < int > g[maxn];

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    rep(i,1,n) {
        g[i].clear();
        rep(j,0,4) rep(k,0,1) f[i][j][k] = 0;
    }
    rep(i,1,n) scanf("%d%d",&val[i],&tra[i]);
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        x ++ , y ++;
        g[x].pb( y );
        g[y].pb( x );
    }
    ans = 0;
}

void mx(lint &x,lint y)
{
    if ( x < y ) x = y;
}

void dfs(int t,int fa)
{
    int y;
    f[t][1][0] = f[t][tra[t]][1] = val[t];
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa ) {
        dfs( y , t );
        rep(j,0,m)
            rep(k,0,m) if ( j + k < m )
                mx( ans , f[t][j][1] + f[y][k][1] );
        rep(j,0,m) mx( ans , max( f[t][j][1] + f[y][m-j][0] , f[t][j][0] + f[y][m-j][1] ) );
        rep(j,1,m) mx( f[t][j+tra[t]][0] , f[y][j][0] + val[t] );
        rep(j,0,m-1) mx( f[t][j+tra[t]][1] , f[y][j][1] + val[t] );
    }
    rep(i,0,m) mx( ans , max( f[t][i][0] , f[t][i][1] ) );
}

void work()
{
    dfs( 1 , 0 );
    cout << ans << endl;
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
