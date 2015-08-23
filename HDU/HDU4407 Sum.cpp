/*
 * Author:  vawait
 * Created Time:  2015/8/23 15:56:43
 * Problem: HDU4407 Sum
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
const int maxn = 400010;
int sum_prime , visit[maxn+10] , prime[maxn+10] , mobius[maxn+10];
int n , m , ty[maxn] , a[maxn] , b[maxn] , c[maxn];

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
}

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        scanf("%d%d%d",&ty[i],&a[i],&b[i]);
        if ( ty[i] == 1 ) scanf("%d",&c[i]);
    }
}

lint calc(lint l,lint r,lint k)
{
    if ( !mobius[k] ) return 0;
    lint x = ( l - 1 ) / k * k + k , y = r / k * k;
    if ( x > y ) return 0;
    return mobius[k] * ( x + y ) * ( r / k - ( l - 1 ) / k ) / 2;
}

lint gcd(lint x,lint y)
{
    return y ? gcd( y , x % y ) : x;
}

void work()
{
    rep(k,1,m) if ( ty[k] == 1 ) {
        lint ans = 0 , l = a[k] , r = b[k] , x = c[k] , m = sqrt( x ) + 0.5;
        rep(i,1,m) if ( x % i == 0 ) {
            ans += calc( l , r , i );
            if ( x / i > i ) ans += calc( l , r , x / i );
        }
        rep(i,1,k-1) if ( ty[i] == 2 && a[i] >= l && a[i] <= r ) {
            if ( gcd( a[i] , x ) == 1 ) ans -= a[i];
            if ( gcd( b[i] , x ) == 1 ) ans += b[i];
        }
        cout << ans << endl;
    } else {
        rep(i,1,k-1) if ( ty[i] == 2 && a[i] == a[k] ) a[i] = 0;
    }
}

int main()
{
    int t;
    pri();
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
