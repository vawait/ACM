/*
 * Author:  vawait
 * Created Time:  2015/7/30 13:03:27
 * Problem: HDU5335 Walk Out
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
int n , m , mx , now = 1 , nex = 0 , vis[1010][1010] , sum[2];
pair < int , int > g[2][10000];
int dx[] = { 0 , 0 , -1 , 1 };
int dy[] = { 1 , -1 , 0 , 0 };
char a[1010][1010];

void init()
{
    scanf("%d%d",&n,&m);
    clr( vis , 0 );
    rep(i,1,n) scanf("%s",a[i]+1);
    clr( sum , 0 );
}

void deal()
{
    queue < pair < int , int > > q;
    q.push( mp( 1 , 1 ) );
    vis[1][1] = 1;
    while ( !q.empty() ) {
        int x = q.front().x , y = q.front().y;
        q.pop();
        rep(i,0,3) {
            int xx = x + dx[i] , yy = y + dy[i];
            if ( xx < 1 || yy < 1 || xx > n || yy > m || a[xx][yy] != '0' || vis[xx][yy] ) continue;
            vis[xx][yy] = 1;
            q.push( mp( xx , yy ) );
        }
    }
    mx = 0;
    rep(i,1,n)
        rep(j,1,m) if ( vis[i][j] && i + j > mx ) mx = i + j;
    sum[now] = 0;
    rep(i,1,n)
        rep(j,1,m) if ( vis[i][j] && i + j == mx ) {
            g[now][++sum[now]] = mp( i , j );
        }
}

void work()
{
    int p = 0;
    mx = 2;
    g[now][sum[now]=1] = mp( 1 , 1 );
    if ( a[1][1] == '1' ) printf("1") , p = 1; else deal();
    rep(k,1,n+m-mx) {
        char c = '1';
        sum[nex] = 0;
        rep(i,1,sum[now]) {
            int x = g[now][i].x , y = g[now][i].y;
            if ( x < n && a[x+1][y] == '0' ) c = '0';
            if ( y < m && a[x][y+1] == '0' ) c = '0';
        }
        rep(i,1,sum[now]) {
            int x = g[now][i].x , y = g[now][i].y;
            if ( x < n && a[x+1][y] == c && !vis[x+1][y] )
                vis[x+1][y] = 1 , g[nex][++sum[nex]] = mp( x + 1 , y );
            if ( y < m && a[x][y+1] == c && !vis[x][y+1] )
                vis[x][y+1] = 1 , g[nex][++sum[nex]] = mp( x , y + 1 );
        }
        if ( p || c == '1' ) printf("%c",c) , p = 1;
        swap( now , nex );
    }
    if ( !p ) printf("0");
    puts("");
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
