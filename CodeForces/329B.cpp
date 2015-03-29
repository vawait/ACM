/*
 * Author:  vawait
 * Created Time:  2015/3/29 14:10:24
 * Problem: CodeForces_329B
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
int n , m , d[1010][1010] , sx , sy , tx , ty;
int dx[] = { 0 , 0 , -1 , 1 };
int dy[] = { 1 , -1 , 0 , 0 };
char a[1010][1010];

void init()
{
    clr( d , 255 );
    rep(i,1,n) scanf("%s",a[i]+1);
    rep(i,1,n)
        rep(j,1,m) {
            if ( a[i][j] == 'E' ) tx = i , ty = j;
            if ( a[i][j] == 'S' ) sx = i , sy = j;
        }
}

bool ok(int x,int y)
{
    return a[x][y] == 'S' || a[x][y] <= '9' && a[x][y] >= '0';
}

void work()
{
    queue < pair < int , int > > q;
    int x , y , xx , yy , sum = 0;
    d[tx][ty] = 0;
    q.push( mp( tx , ty ) );
    while ( !q.empty() ) {
        x = q.front().x , y = q.front().y;
        q.pop();
        rep(i,0,3) {
            xx = x + dx[i] , yy = y + dy[i];
            if ( ok( xx , yy ) && d[xx][yy] < 0 ) {
                d[xx][yy] = d[x][y] + 1;
                q.push( mp( xx , yy ) );
            }
        }
    }
    rep(i,1,n)
        rep(j,1,m) if ( d[i][j] >= 0 && ok( i , j ) && a[i][j] != 'S' && d[i][j] <= d[sx][sy] ) 
            sum += a[i][j] - '0';
    printf("%d\n",sum);
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
