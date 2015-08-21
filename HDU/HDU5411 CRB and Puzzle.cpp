/*
 * Author:  vawait
 * Created Time:  2015/8/20 14:47:54
 * Problem: HDU5411 CRB and Puzzle
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
const lint mod = 2015;
int n , m ;

struct nodd
{
    lint a[70][70];
    void cl() { clr( a , 0 ) ; }
} a , b , c;

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    m ++;
    a.cl();
    a.a[1][0] = 1;
    b.cl();
    rep(i,1,n) b.a[0][i] = 1;
    rep(i,1,n) {
        scanf("%d",&x);
        while ( x -- ) {
            scanf("%d",&y);
            b.a[i][y] = 1;
        }
    }
    n ++;
    rep(i,0,n) b.a[i][n] = 1;
}

void km(nodd &a,nodd &b)
{
    c.cl();
    rep(i,0,n)
        rep(j,0,n)
            rep(k,0,n) c.a[i][j] += a.a[i][k] * b.a[k][j];
    rep(i,0,n)
        rep(j,0,n) a.a[i][j] = c.a[i][j] % mod;
}

void work()
{
    while ( m ) {
        if ( m & 1 ) km( a , b );
        km( b , b );
        m >>= 1;
    }
    cout << a.a[1][n] << endl;
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
