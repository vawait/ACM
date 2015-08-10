/*
 * Author:  vawait
 * Created Time:  2015/8/7 13:40:20
 * Problem: HDU4374 One hundred layer
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
int n , m , x , t , a[110][11000] , f[110][11000];
pair < int , int > q[11000];

void init()
{
    int y;
    rep(i,0,m) a[n+1][i] = 0;
    rep(i,1,n) 
        rep(j,1,m) scanf("%d",&y) , a[i][j] = a[i][j-1] + y;
    y = -1e9;
    rep(i,0,n+1)
        rep(j,1,m) f[i][j] = y;
    f[1][x] = a[1][x] - a[1][x-1];
}

void work()
{
    int l , r , y;
    rep(i,1,n+1) {
        l = 1 , r = 0;
        rep(j,1,m) {
            while ( l <= r && q[r].x <= f[i-1][j] - a[i-1][j] ) r --;
            q[++r] = mp( f[i-1][j] - a[i-1][j] , j );
            while ( l <= r && j - q[l].y > t ) l ++;
            y = q[l].y;
            f[i][j] = max( f[i][j] , f[i-1][y] + a[i-1][j] - a[i-1][y] + a[i][j] - a[i][j-1] );
        }
        l = 1 , r = 0;
        red(j,m,1) {
            while ( l <= r && q[r].x <= f[i-1][j] + a[i-1][j-1] ) r --;
            q[++r] = mp( f[i-1][j] + a[i-1][j-1] , j );
            while ( l <= r && q[l].y - j > t ) l ++;
            y = q[l].y;
            f[i][j] = max( f[i][j] , f[i-1][y] + a[i-1][y-1] - a[i-1][j-1] + a[i][j] - a[i][j-1] );
        }
    }
    int mx = -1e9;
    rep(i,1,m) mx = max( mx , f[n+1][i] );
    printf("%d\n",mx);
}

int main()
{
    while ( cin >> n >> m >> x >> t ) {
        init();
        work();
    }
    return 0;
}
