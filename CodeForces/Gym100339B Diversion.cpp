/*
 * Author:  vawait
 * Created Time:  2015/9/2 14:12:16
 * Problem: Gym100339B Diversion
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
int n , m , ans = 0 , vis[maxn] , f[maxn] , sum[maxn];
vector < int > g[maxn] , ask[maxn];

int find(int t)
{
    return f[t] == t ? t : f[t] = find( f[t] );
}

void init()
{
    int x , y , ty;
    scanf("%d%d",&n,&m);
    rep(i,1,n) f[i] = i;
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&ty);
        if ( ty ) {
            g[x].pb( y );
            g[y].pb( x );
        } else {
            ask[x].pb( y );
            ask[y].pb( x );
        }
    }
}

void lca(int t,int fa)
{
    int y;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa ) {
        lca( y , t );
        f[find(y)] = t;
    }
    red(i,ask[t].size()-1,0) if ( vis[y=ask[t][i]] ) {
        int lca = find( y ) , x = t;
        if ( lca == x || lca == y ) {
            if ( lca == y ) swap( x , y );
            sum[x] --;
            sum[y] ++;
        } else {
            sum[lca] -= 2;
            sum[x] ++;
            sum[y] ++;
        }
    }
    vis[t] = 1;
}

void dfs(int t,int fa)
{
    red(i,g[t].size()-1,0) if ( g[t][i] != fa ) {
        dfs( g[t][i] , t );
        sum[t] += sum[g[t][i]];
    }
    if ( sum[t] == 1 ) ans ++;
}

void work()
{
    lca( 1 , -1 );
    dfs( 1 , -1 );
    cout << ans << endl;
}

int main()
{
    freopen("diversion.in","r",stdin);
    freopen("diversion.out","w",stdout);
    init();
    work();
    return 0;
}
