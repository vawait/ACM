/*
 * Author:  vawait
 * Created Time:  2015/3/29 13:27:36
 * Problem: CodeForces_329A
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
int n , vx[1000] , vy[1000];
int ansx , qx1[1000] , qx2[1000] , ansy , qy1[1000] , qy2[1000];
pair < int , int > qx[1000] , qy[1000] , *q;
char a[200][200];

void init()
{
    clr( vx , 1 );
    clr( vy , 1 );
    rep(i,1,n) scanf("%s",a[i]+1);
    ansx = ansy = 0;
}

void work()
{
    rep(i,1,n)
        rep(j,1,n) if ( a[i][j] == '.' ) {
            if ( vx[i] )
                qx[++ansx] = mp( i , j ) , vx[i] = 0;
            if ( vy[j] )
                qy[++ansy] = mp( i , j ) , vy[j] = 0;
        }
    int xx = 0 , yy = 0 , ans;
    rep(i,1,n) xx = max( xx , vx[i] ) , yy = max( yy , vy[i] );
    if ( xx && yy ) {
        puts("-1");
        return;
    }
    if ( !xx ) {
        ans = ansx , q = qx;
    } else {
        q = qy , ans = ansy;
    }
    rep(i,1,ans) printf("%d %d\n",q[i].x,q[i].y);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
