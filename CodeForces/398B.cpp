/*
 * Author:  vawait
 * Created Time:  2015/2/28 14:54:42
 * Problem: CodeForces_398B
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
const int maxn = 2010;
int n , m , xx , yy , vx[maxn] , vy[maxn];
double f[maxn][maxn];

void init()
{
    int x , y;
    clr( vx , 0 );
    clr( vy , 0 );
    while ( m -- ) scanf("%d%d",&x,&y) , vx[x] = 1 , vy[y] = 1;
    xx = yy = 0;
    rep(i,1,n) xx += !vx[i] , yy += !vy[i];
    f[0][0] = 0;
}

double pro(double x,double y)
{
    return ( n * x - x * y ) / ( n * n );
}

void work()
{
    rep(i,0,n)
        rep(j,0,n) {
            if ( !i && !j ) continue;
            double p1 = ( n * n - n * ( i + j ) + i * j ) / ( 1.0 * n * n );
            double x = 1 - p1;
            if ( i ) x += f[i-1][j] * pro( i , j );
            if ( j ) x += f[i][j-1] * pro( j , i );
            if ( i && j ) x += f[i-1][j-1] * i * j / ( n * n );
            f[i][j] = ( x + p1 ) / ( 1 - p1 );
        }
    printf("%.9lf\n",f[xx][yy]);
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
