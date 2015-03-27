/*
 * Author:  vawait
 * Created Time:  2015/3/27 1:59:26
 * Problem: CodeForces_525D
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
int n , m , v[2010][2010];
int d1[][2] = {{0,-1} , {0,-1} , {0,1}  , { 0 , 1 } , { 0 , -1 } , { 0 , -1 }  , { 0 , 1 } , { 0 , 1 } , {1,0},{1,0},{-1,0},{-1,0}};
int d2[][2] = {{1,0} , {-1,0} , {-1,0} , { 1 , 0 } , { 1 , -1 } , { -1 , -1 } , { 1 , 1 } , { -1 , 1 } ,{1,1},{1,-1},{-1,-1},{-1,1}};
int dd[][2] = {{1,-1} , {-1,-1} , {-1,1} , { 1 , 1 } , { 1 , 0 }  , { -1 , 0 }  , { 1 , 0 } , { -1 , 0 },{0,1},{0,-1},{0,-1},{0,1}};
char a[2010][2010];

void init()
{
    rep(i,1,n) scanf("%s",a[i]+1);
    rep(i,1,n) a[i][0] = a[i][m+1] = '1';
    rep(i,1,m) a[0][i] = a[n+1][i] = '1';
    clr( v , 0 );
}

void work()
{
    queue < pair < int , int > > q;
    int x , y , xx , yy;
    rep(i,1,n)
        rep(j,1,m) if ( a[i][j] == '.' ) q.push( mp( i , j ) ) , v[i][j] = 1;
    while ( !q.empty() ) {
        x = q.front().x , y = q.front().y;
        v[x][y] = 0;
        q.pop();
        rep(i,0,11) if ( a[x+d1[i][0]][y+d1[i][1]] == '.' && a[x+d2[i][0]][y+d2[i][1]] == '.' && a[x+dd[i][0]][y+dd[i][1]] != '.' ) {
            xx = x + dd[i][0]; yy = y + dd[i][1];
            a[xx][yy] = '.';
            if ( !v[xx][yy] ) q.push( mp( xx , yy ) ) , v[xx][yy] = 1;
        }
    }
    rep(i,1,n) {
        rep(j,1,m) printf("%c",a[i][j]);
        puts("");
    }
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
