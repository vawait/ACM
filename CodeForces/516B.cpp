/*
 * Author:  vawait
 * Created Time:  2015/2/18 0:57:58
 * Problem: CodeForces_516B
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
int n , m , sum;
int dx[] = { 0 , 1 , -1 , 0 };
int dy[] = { 1 , 0 , 0 , -1 };
char dd[] = { '>' , 'v' , '^' , '<' };
char a[2010][2010];

int calc(int x,int y)
{
    int s = 0;
    rep(i,0,3) if ( a[x+dx[i]][y+dy[i]] == '.' ) s ++;
    return s;
}

void init()
{
    clr( a , 0 );
    rep(i,1,n) scanf("%s",a[i]+1);
    sum = 0;
    rep(i,1,n)
        rep(j,1,m) sum += ( a[i][j] == '.' );
}

void work()
{
    queue < int > qx , qy;
    int x , y , xx , yy;
    rep(i,1,n)
        rep(j,1,m) if ( a[i][j] == '.' && calc( i , j ) == 1 ) qx.push( i ) , qy.push( j );
    while ( !qx.empty() ) {
        x = qx.front(); y = qy.front();
        qx.pop(); qy.pop();
        if ( a[x][y] != '.' ) continue;
        sum -= 2;
        rep(i,0,3) if ( a[xx=x+dx[i]][yy=y+dy[i]] == '.' ) {
            a[xx][yy] = dd[i];
            a[x][y] = dd[3-i];
            rep(j,0,3) if ( a[x+dx[j]][y+dy[j]] == '.' && calc( x + dx[j] , y + dy[j] ) == 1 ) qx.push( x + dx[j] ) , qy.push( y + dy[j] );
            rep(j,0,3) if ( a[xx+dx[j]][yy+dy[j]] == '.' && calc( xx + dx[j] , yy + dy[j] ) == 1 ) qx.push( xx + dx[j] ) , qy.push( yy + dy[j] );
        }
    }
    if ( sum ) puts("Not unique"); else {
        rep(i,1,n) {
            rep(j,1,m) printf("%c",a[i][j]);
            puts("");
        }
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
