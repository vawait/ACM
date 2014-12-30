/*
 * Author:  vawait
 * Created Time:  2014/12/30 23:46:29
 * Problem: CodeForces_500D
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
int n , m , gl[110000] , sum[110000] , gx[110000] , gy[110000] , fa[110000];
double ans;
vector < int > g[110000];

void dfs(int t)
{
    int y;
    sum[t] = 1;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa[t] ) {
        fa[y] = t;
        dfs( y );
        sum[t] += sum[y];
    }
}

void calc(double n,double m,double l)
{
    if ( n > 1 ) ans += n * ( n - 1 ) * m * l;
    if ( m > 1 ) ans += m * ( m - 1 ) * n * l;
}

void init()
{
    rep(i,1,n) g[i].clear();
    rep(i,1,n-1) {
        scanf("%d%d%d",&gx[i],&gy[i],&gl[i]);
        g[gx[i]].pb( gy[i] );
        g[gy[i]].pb( gx[i] );
    }
    ans = 0;
    fa[1] = 0;
    dfs( 1 );
    rep(i,1,n-1) {
        int x = fa[gx[i]] == gy[i] ? gx[i] : gy[i];
        calc( sum[x] , n - sum[x] , gl[i] );
    }
}

void work()
{
    int x , y , p;
    double num = (double) n * ( n - 1 ) * ( n - 2 ) / 6;
    scanf("%d",&m);
    while ( m -- ) {
        scanf("%d%d",&p,&y);
        x = fa[gx[p]] == gy[p] ? gx[p] : gy[p];
        calc( sum[x] , n - sum[x] , y - gl[p] );
        gl[p] = y;
        printf("%.9f\n",ans/num);
    }
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
