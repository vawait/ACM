/*
 * Author:  vawait
 * Created Time:  2015/7/22 14:10:45
 * Problem: HDU4123 Bob’s Race
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
const int maxn = 101000;
int n , m , vis[maxn] , q1[maxn] , q2[maxn];
lint d[maxn] , f[maxn];
vector < pair < int , int > > g[maxn];

void bfs(int t)
{
    int x , y;
    queue < int > q;
    q.push( t );
    clr( d , 1 );
    d[t] = 0;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        vis[x] = 0;
        red(i,g[x].size()-1,0) if ( d[x] + g[x][i].y < d[y=g[x][i].x] ) {
            d[y] = d[x] + g[x][i].y;
            if ( !vis[y] ) vis[y] = 1 , q.push( y );
        }
    }
}

void init()
{
    int x , y , s , t , dd;
    rep(i,1,n) g[i].clear();
    rep(i,2,n) {
        scanf("%d%d%d",&x,&y,&dd);
        g[x].pb( mp( y , dd ) );
        g[y].pb( mp( x , dd ) );
    }
    bfs( 1 );
    lint mx = -1;
    rep(i,1,n) if ( d[i] > mx ) mx = d[i] , s = i;
    bfs( s );
    mx = -1;
    rep(i,1,n) if ( d[i] > mx ) mx = d[i] , t = i;
    rep(i,1,n) f[i] = d[i];
    bfs( t );
    rep(i,1,n) f[i] = max( f[i] , d[i] );
}

void work()
{
    while ( m -- ) {
        int Q , ans = 1 , l1 = 1 , r1 = 1 , l2 = 1 , r2 = 1 , p = 1;
        q1[1] = q2[1] = 1;
        scanf("%d",&Q);
        rep(i,2,n) {
            while ( l1 <= r1 && f[q1[r1]] >= f[i] ) r1 --;
            q1[++r1] = i;
            while ( l2 <= r2 && f[q2[r2]] <= f[i] ) r2 --;
            q2[++r2] = i;
            while ( f[q2[l2]] - f[q1[l1]] > Q ) {
                p ++;
                while ( l1 <= r1 && q1[l1] < p ) l1 ++;
                while ( l2 <= r2 && q2[l2] < p ) l2 ++;
            }
            ans = max( ans , i - p + 1 );
        }
        printf("%d\n",ans);
    }
}

int main()
{
    while ( scanf("%d%d",&n,&m) && n ) {
        init();
        work();
    }
    return 0;
}
