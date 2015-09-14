/*
 * Author:  vawait
 * Created Time:  2015/9/12 19:51:12
 * Problem: HDU5434 Peace small elephant
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
const lint mod = 1000000007;
int n , m , l , d[20] , f[20];

struct nodd
{
    lint a[130][130];
    void cl() { clr( a , 0 ); }
} a , b , c;

int calc(int x,int y)
{
    clr( d , 0 );
    clr( f , 0 );
    rep(i,1,10) d[i] = x & 1 , x >>= 1;
    rep(i,1,10) f[i] = y & 1 , y >>= 1;
    rep(i,1,10) if ( f[i] && !d[i] && ( d[i-1] && !f[i-1] || d[i+1] && !f[i+1] ) ) return 0;
    return 1;
}

void init()
{
    l = ( 1 << m ) - 1 ;
    a.cl();
    b.cl();
    a.a[0][0] = 1;
    rep(i,0,l)
        rep(j,0,l) b.a[i][j] = calc( i , j );
}

void km(nodd &a,nodd &b)
{
    c.cl();
    rep(i,0,l)
        rep(j,0,l)
            rep(k,0,l) ( c.a[i][j] += a.a[i][k] * b.a[k][j] ) %= mod;
    a = c;
}

void work()
{
    while ( n ) {
        if ( n & 1 ) km( a , b );
        km( b , b );
        n >>= 1;
    }
    lint ans = 0;
    rep(i,0,l) ans += a.a[0][i];
    ans %= mod;
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
