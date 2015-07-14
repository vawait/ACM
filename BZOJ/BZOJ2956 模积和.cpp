/*
 * Author:  vawait
 * Created Time:  2015/7/14 14:29:08
 * Problem: BZOJ2956 模积和
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
const lint mod = 19940417;
const lint mm = 3323403;
lint n , m;

void init()
{
    cin >> n >> m;
}

lint calc(lint n)
{
    lint ans = 0;
    for ( lint i = 1 , p; i <= n; i = p + 1 ) {
        p = n / ( n / i );
        ( ans += n / i * ( ( p + i ) * ( p - i + 1 ) / 2 % mod ) ) %= mod;
    }
    return ans;
}

lint sum(lint n)
{
    return n * ( n + 1 ) % mod * ( 2 * n + 1 ) % mod * mm % mod;
}

void work()
{
    lint ans = ( n * n - calc( n ) ) % mod * ( ( m * m - calc( m ) ) % mod ) % mod;
    if ( n > m ) swap( n , m );
    ( ans -= n * m % mod * n % mod ) %= mod;
    for ( lint i = 1 , p; i <= n; i = p + 1 ) {
        p = min( n / ( n / i ) , m / ( m / i ) );
        ans += ( m / i * n + n / i * m ) % mod * ( ( p + i ) * ( p - i + 1 ) / 2 % mod ) % mod;
        ans -= ( m / i ) * ( n / i ) % mod * ( sum( p ) - sum( i - 1 ) ) % mod;
        ans %= mod;
    }
    ans %= mod;
    ans = ( ans + mod ) % mod;
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
