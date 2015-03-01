/*
 * Author:  vawait
 * Created Time:  2015/2/28 12:37:05
 * Problem: CodeForces_388B
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
const int len = 27;
int n , m , a[20] , k , g[2010][2010];

void add(int x,int y)
{
    g[x][y] = g[y][x] = 1;
}

void init()
{
    n = 2;
    clr( g , 0 );
    m = 0;
    while ( k ) a[++m] = k % 10 , k /= 10;
}

void deal(int m,int p)
{
    int x = 1;
    rep(i,1,m) {
        rep(j,1,10) add( x , ++n );
        n ++;
        rep(j,1,10) add( n , n - j );
        x = n;
    }
    rep(i,1,p) add( x , ++n );
    n ++;
    rep(i,1,p) add( n , n - i );
    rep(i,1+2*(1+m),len) {
        add( n , n + 1 );
        n ++;
    }
    add( n , 2 );
}

void work()
{
    red(i,m,1) if ( a[i] ) deal( i - 1 , a[i] );
    printf("%d\n",n);
    rep(i,1,n) {
        rep(j,1,n) printf("%c",g[i][j]?'Y':'N');
        puts("");
    }
}

int main()
{
    while ( cin >> k ) {
        init();
        work();
    }
    return 0;
}
