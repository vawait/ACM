/*
 * Author:  vawait
 * Created Time:  2015/9/9 14:00:06
 * Problem: BZOJ3329 Xorequ
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
const lint mod = 1e9 + 7;
lint n , m , f[70][2] , a[70];

struct nodd
{
    lint a[2][2];
} A , B;

void init()
{
    f[0][0] = 1;
    rep(i,1,63) {
        f[i][0] = f[i-1][0] + f[i-1][1];
        f[i][1] = f[i-1][0];
    }
    cin >> n;
    m = n;
    clr( a , 0 );
    rep(i,1,64) a[i] = m & 1 , m >>= 1;
}

nodd km(const nodd &a,const nodd &b)
{
    nodd c;
    clr( c.a , 0 );
    rep(i,0,1)
        rep(j,0,1)
            rep(k,0,1) ( c.a[i][j] += a.a[i][k] * b.a[k][j] ) %= mod;
    return c;
}

void work()
{
    lint ans = 1;
    rep(i,1,64) if ( a[i] && a[i+1] ) ans = 0;
    red(i,64,1) if ( a[i] ) {
        ans += f[i][0];
        if ( a[i+1] ) break;
    }
    ans --;
    cout << ans << endl;
    
    clr( A.a , 0 );
    A.a[0][0] = 1;
    B.a[0][0] = B.a[1][0] = B.a[0][1] = 1;
    B.a[1][1] = 0;
    while ( n ) {
        if ( n & 1 ) A = km( A , B );
        B = km( B , B );
        n >>= 1;
    }
    ans = ( A.a[0][0] + A.a[0][1] ) % mod;
    cout << ans << endl;
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
