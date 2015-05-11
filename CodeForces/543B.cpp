/*
 * Author:  vawait
 * Created Time:  2015/5/11 15:58:03
 * Problem: CodeForces_543B
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
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
int n , m , d[3010][3010];
int x1 , y1 , t1 , x2 , y2 , t2;
vector < int > g[3010];

void init()
{
    int x , y;
    rep(i,1,n) g[i].clear();
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    scanf("%d%d%d",&x1,&y1,&t1);
    scanf("%d%d%d",&x2,&y2,&t2);
}

void bfs(int t)
{
    queue < int > q;
    int x , y;
    q.push( t );
    clr( d[t] , 255 );
    d[t][t] = 0;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        red(i,g[x].size()-1,0) if ( d[t][y=g[x][i]] < 0 ) {
            d[t][y] = d[t][x] + 1;
            q.push( y );
        }
    }
}

int calc(int i,int j,int x,int y)
{
    return min( d[i][x] + d[j][y] , d[i][y] + d[j][x] );
}

void work()
{
    rep(i,1,n) bfs( i );
    if ( d[x1][y1] > t1 || d[x2][y2] > t2 ) {
        puts("-1");
        return;
    }
    
    int ans = d[x1][y1] + d[x2][y2];
    rep(i,1,n)
        rep(j,1,n) if ( calc( i , j , x1 , y1 ) + d[i][j] <= t1 && calc( i , j , x2 , y2 ) + d[i][j] <= t2 )
            ans = min( ans , d[i][j] + calc( i , j , x1 , y1 ) + calc( i , j , x2 , y2 ) );
    cout << m - ans << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
