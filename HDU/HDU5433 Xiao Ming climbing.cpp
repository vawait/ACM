/*
 * Author:  vawait
 * Created Time:  2015/9/12 19:21:41
 * Problem: HDU5433 Xiao Ming climbing
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
const double mx = 1e7;
int n , m , k , x , y , vis[60][60];
int dx[] = { -1 , 1 , 0 , 0 };
int dy[] = { 0 , 0 , -1 , 1 };
double d[60][60][60];
char a[60][60];

void init()
{
    scanf("%d%d%d",&n,&m,&k);
    rep(r,0,k)
        rep(i,1,n)
            rep(j,1,m)
                d[r][i][j] = mx * 100;
    clr( a , 0 );
    rep(i,1,n) scanf("%s",a[i]+1);
    scanf("%d%d",&x,&y);
    d[k][x][y] = 0;
}

void work()
{
    red(kk,k,2) 
        rep(i,1,n) rep(j,1,m) if ( d[kk][i][j] < mx )
            rep(r,0,3) {
                int x = i + dx[r] , y = j + dy[r];
                if ( x > n || x < 1 || y > m || y < 1 || a[x][y] == '#' ) continue;
                double dd = d[kk][i][j] + abs( a[i][j] - a[x][y] ) / double( kk );
                if ( dd < d[kk-1][x][y] ) d[kk-1][x][y] = dd;
            }
    double ans = mx;
    scanf("%d%d",&x,&y);
    rep(i,1,k) ans = min( ans , d[i][x][y] );
    if ( ans > 1e6 ) puts("No Answer"); else printf("%.2f\n",ans);
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
