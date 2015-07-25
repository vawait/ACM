/*
 * Author:  vawait
 * Created Time:  2015/7/25 15:08:37
 * Problem: HDU4169 Wealthy Family
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
const int maxn = 151000;
int root , n , m , w[maxn] , f[maxn] , use[maxn];
vector < int > g[maxn];

void dfs(int t)
{
    int y , mx = -1e8;
    red(i,g[t].size()-1,0) {
        dfs( y = g[t][i] );
        w[t] = max( w[t] , w[y] );
        f[t] = max( f[t] , max( f[y] , mx + w[y] ) );
        mx = max( mx , w[y] );
    }
}

void init()
{
    int x;
    rep(i,0,n) g[i].clear() , use[i] = 0;
    rep(i,1,n) {
        f[i] = -1e8;
        scanf("%d%d",&x,&w[i]);
        if ( !x ) root = i; else g[x].pb( i );
    }
    dfs( root );
}

void work()
{
    priority_queue < pair < int , int > > q;
    int ans = 0;
    q.push( mp( w[root] , root ) );
    while ( m ) {
        if ( q.empty() ) {
            puts("impossible");
            return;
        }
        int x = q.top().y;
        q.pop();
        if ( use[x] ) {
            m ++;
            ans -= w[x];
            red(i,g[x].size()-1,0) q.push( mp( w[g[x][i]] , g[x][i] ) );
        } else {
            m --;
            ans += w[x];
            use[x] = 1;
            q.push( mp( f[x] - w[x] , x ) );
        }
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
