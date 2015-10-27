/*
 * Author:  vawait
 * Created Time:  2015/9/17 15:05:26
 * Problem: HDU4650 Minimum Average Weight Path
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
const int maxn = 110;
int n , m , g[maxn][maxn] , vis[maxn][maxn] , f[maxn][maxn];
double ans[maxn][maxn];

void init()
{
    int x , y;
    clr( g , 1 );
    clr( vis , 0 );
    clr( ans , 100 );
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        scanf("%d",&g[x][y]);
        vis[x][y] = 1;
    }
    rep(k,1,n)
        rep(i,1,n) rep(j,1,n) vis[i][j] |= vis[i][k] & vis[k][j];
}

void work()
{
    rep(t,1,n) {
        clr( f , 1 );
        f[0][t] = 0; 
        rep(k,0,n)
            rep(i,1,n)
                rep(j,1,n) f[k+1][j] = min( f[k+1][j] , f[k][i] + g[i][j] );
        rep(k,1,n)
            rep(i,1,n) {
                ans[t][i] = min( ans[t][i] , (double)f[k][i] / k );
            }
    }
    rep(i,1,n)
        rep(j,1,n) {
            if ( vis[i][j] ) {
                double p = ans[i][j];
                rep(k,1,n) if ( vis[i][k] && vis[k][j] ) p = min( p , ans[k][k] );
                printf("%.3f",p);
            } else {
                printf("NO");
            }
            if ( j == n ) printf("\n"); else printf(" ");
        }
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
