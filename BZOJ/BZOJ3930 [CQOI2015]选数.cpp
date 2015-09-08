/*
 * Author:  vawait
 * Created Time:  2015/9/8 14:40:59
 * Problem: BZOJ3930 [CQOI2015]选数
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
const int maxn = 1e7;
lint n , k , l , r;
int sum_prime , visit[maxn+10] , prime[maxn+10] , mobius[maxn+10];
map < int , int > SumMo;

void pri()
{
    sum_prime = 0;
    mobius[1] = 1;
    rep(i,2,maxn) {
        if ( !visit[i] ) prime[++sum_prime] = i , mobius[i] = -1;
        for ( int j = 1; j <= sum_prime && i * prime[j] <= maxn; j++ ) {
            visit[i*prime[j]] = 1;
            if ( i % prime[j] ) mobius[i*prime[j]] = -mobius[i]; else break;
        }
    }
    rep(i,2,maxn) mobius[i] += mobius[i-1];
}

void init()
{
    pri();
    cin >> n >> k >> l >> r;
    l = ( l - 1 ) / k; r = r / k;
}

lint Sum(int x)
{
    if( x <= maxn ) return mobius[x];
    if( SumMo.find(x) != SumMo.end() ) return SumMo[x];
    lint i , last , ans = 1;
    for( i = 1; i <= x; i = last + 1 ) {
        last = x / ( x / i );
        if( x / i - 1 )
            ans -= ( Sum(last) - Sum(i-1) ) * ( x / i - 1 );
    }
    return SumMo[x] = ans;
}

lint km(lint a,lint n)
{
    lint s = 1;
    while ( n ) {
        if ( n & 1 ) ( s *= a ) %= mod;
        ( a *= a ) %= mod;
        n >>= 1;
    }
    return s;
}

void work()
{
    lint ans = 0 , p , mx = 1e9;
    for ( lint i = 1; i <= r; i = p + 1 ) {
        p = min( l / i ? l / ( l / i ) : mx , r / ( r / i ) );
        ans += km( r / i - l / i , n ) * ( Sum( p ) - Sum( i - 1 ) );
        ans %= mod;
    }
    ( ans += mod ) %= mod;
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
