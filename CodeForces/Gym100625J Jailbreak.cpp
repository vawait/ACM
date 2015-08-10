/*
 * Author:  vawait
 * Created Time:  2015/8/9 13:38:04
 * Problem: Gym100625J Jailbreak
 */
#include<cstdio>
#include<iostream>
#include<cstring>
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
int n , m , d[120][120] , d2[120][120] , d3[120][120] , vis[120][120];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };
int x1 , x2 , y1 , y2;
char a[120][120];

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",a[i]+1);
    n ++; m ++;
    rep(i,1,m) a[0][i] = a[n][i] = '.';
    rep(i,1,n) a[i][0] = a[i][m] = '.';
    x1 = -1;
    rep(i,1,n)
        rep(j,1,m) if ( a[i][j] == '$' ) {
            if ( x1 < 0 ) x1 = i , y1 = j;
            else x2 = i , y2 = j;
        }
}

void spfa(int x,int y)
{
    int xx , yy;
    queue < pair < int , int > > q;
    q.push( mp( x , y ) );
    rep(i,0,n)
        rep(j,0,m) d[i][j] = 100000;
    d[x][y] = 0;
    while ( !q.empty() ) {
        x = q.front().x , y = q.front().y;
        q.pop(); vis[x][y] = 0;
        rep(i,0,3) {
            xx = x + dx[i] , yy = y + dy[i];
            if ( xx < 0 || xx > n || yy < 0 || yy > m || a[xx][yy] == '*' ) continue;
            if ( d[x][y] + ( a[xx][yy] == '#' ) < d[xx][yy] ) {
                d[xx][yy] = d[x][y] + ( a[xx][yy] == '#' );
                if ( !vis[xx][yy] ) vis[xx][yy] = 1 , q.push( mp( xx , yy ) );
            }
        }
    }
}

void work()
{
    spfa( x1 , y1 );
    rep(i,0,n)
        rep(j,0,m) d2[i][j] = d[i][j]; 
    spfa( x2 , y2 );
    rep(i,0,n)
        rep(j,0,m) d3[i][j] = d[i][j];
    spfa( 0 , 0 );
    
    int ans = d[x1][y1] + d[x2][y2];
    rep(i,1,n)
        rep(j,0,m) ans = min( ans , d[i][j] + d2[i][j] + d3[i][j] - ( a[i][j] == '#' ? 2 : 0 ) );
    printf("%d\n",ans);
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
