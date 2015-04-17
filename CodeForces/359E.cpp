/*
 * Author:  vawait
 * Created Time:  2015/4/6 12:36:06
 * Problem: CodeForces_359E
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
int n , sum , x , y , a[510][510] , vis[510][510];
int dx[] = { -1 , 0 , 0 , 1 };
int dy[] = { 0 , 1 , -1 , 0 };
char d[] = { 'U' , 'R' , 'L' , 'D' };
char ans[3001000];

void init()
{
    clr( a , 0 );
    clr( vis , 0 );
    rep(i,1,n)
        rep(j,1,n) scanf("%d",&a[i][j]);
    sum = 0;
}

void dfs1(int x,int y)
{
    if ( a[x][y] == 0 ) {
        a[x][y] = 1;
        ans[++sum] = '1';
    }
    vis[x][y] = 1;
    rep(i,0,3) {
        int xx = x + dx[i] , yy = y + dy[i] , ok = 0;
        if ( vis[xx][yy] ) continue;
        int x1 = xx , y1 = yy;
        while ( 1 ) {
            if ( a[x1][y1] ) {
                ok = 1;
                break;
            }
            if ( x1 > n || x1 < 1 || y1 > n || y1 < 1 ) break;
            x1 += dx[i] , y1 += dy[i];
        }
        if ( ok ) {
            ans[++sum] = d[i];
            dfs1( xx , yy );
            ans[++sum] = d[3-i];
        }
    }
}

void dfs2(int x,int y)
{
    a[x][y] = 0;
    rep(i,0,3) {
        int xx = x + dx[i] , yy = y + dy[i];
        if ( a[xx][yy] ) {
            ans[++sum] = d[i];
            dfs2( xx , yy );
            ans[++sum] = d[3-i];
        }
    }
    ans[++sum] = '2';
}

void work()
{
    dfs1( x , y );
    dfs2( x , y );
    rep(i,1,n)
        rep(j,1,n) if ( a[i][j] ) {
            puts("NO");
            return;
        }
    puts("YES");
    rep(i,1,sum) printf("%c",ans[i]);
    puts("");
}

int main()
{
    while ( cin >> n >> x >> y ) {
        init();
        work();
    }
    return 0;
}
