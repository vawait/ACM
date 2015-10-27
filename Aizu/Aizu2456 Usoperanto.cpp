/*
 * Author:  vawait
 * Created Time:  2015/10/7 12:29:15
 * Problem: Aizu2456 Usoperanto
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
const int maxn = 1001000;
int n , m , w[maxn] , fa[maxn] , que[maxn];
lint ans;
vector < int > g[maxn];

void init()
{
    n --;
    rep(i,0,n) g[i].clear();
    rep(i,0,n) {
        scanf("%d%d",&w[i],&fa[i]);
        if ( fa[i] >= 0 ) g[fa[i]].pb( i );
    }
    ans = m = 0;
}

/*
void dfs(int t)
{
    red(i,g[t].size()-1,0) {
        dfs( g[t][i] );
        g[t][i] = w[g[t][i]];
        w[t] += g[t][i];
    }
    sort( g[t].begin() , g[t].end() );
    int sum = 0;
    for ( int i = 0; i < (int)g[t].size(); i ++ ) {
        ans += sum;
        sum += g[t][i];
    }
}
*/

void bfs(int t)
{
    queue < int > q;
    q.push( t );
    int x;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        que[++m] = x;
        red(i,g[x].size()-1,0) {
            q.push( g[x][i] );
        }
    }
}

void work()
{
    int t;
    rep(i,0,n) if ( fa[i] < 0 ) bfs( i );
    red(j,m,1) {
        t = que[j];
        red(i,g[t].size()-1,0) {
            g[t][i] = w[g[t][i]];
            w[t] += g[t][i];
        }
        sort( g[t].begin() , g[t].end() );
        int sum = 0;
        for ( int i = 0; i < (int)g[t].size(); i ++ ) {
            ans += sum;
            sum += g[t][i];
        }
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
