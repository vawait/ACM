/*
 * Author:  vawait
 * Created Time:  2015/7/26 15:34:51
 * Problem: HDU4219 Randomization?
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
int n , L , S;
double p , f[70][600] , sum[70][600] , f2[70][600];
vector < int > g[70];

void init()
{
    int x , y;
    scanf("%d%d%d",&n,&L,&S);
    rep(i,1,n) g[i].clear();
    clr( f , 0 ); clr( sum , 0 );
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    p = 1.0 / ( L + 1 );
}

void dfs(int t,int fa)
{
    int y , mx;
    f[t][0] = 1;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa ) {
        dfs( y , t );
        
        clr( f2[y] , 0 );
        rep(j,0,L) 
            rep(k,0,S) f2[y][j+k] += f[y][k] * p;
        
        sum[t][0] = f[t][0];
        rep(j,1,S) sum[t][j] = sum[t][j-1] + f[t][j];
        sum[y][0] = f2[y][0];
        rep(j,1,S) sum[y][j] = sum[y][j-1] + f2[y][j];
        
        clr( f2[t] , 0 );
        rep(j,0,S) {
            mx = min( S - j , j );
            if ( mx >= 0 ) {
                f2[t][j] = f[t][j] * sum[y][mx] + f2[y][j] * sum[t][mx];
                if ( j + j <= S ) f2[t][j] -= f[t][j] * f2[y][j];
            }
        }
        rep(j,0,S) f[t][j] = f2[t][j];
    }
}

void work()
{
    dfs( 1 , -1 );
    double ans = 0;
    rep(i,0,S) ans += f[1][i];
    printf("%.6f\n",ans);
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case %d: ",i);
        init();
        work();
    }
    return 0;
}
