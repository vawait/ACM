/*
 * Author:  vawait
 * Created Time:  2015/9/12 20:14:39
 * Problem: HDU5435 A serious math problem
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
const int mod = 1e9 + 7;
const int maxn = 101000;
int n , a[maxn];
lint ans , f[maxn][16];
char c[maxn];

void add(lint &x,lint y)
{
    x += y;
    if ( x >= mod ) x -= mod;
}

void pri()
{
    f[0][0] = 1;
    rep(i,0,100100)
        rep(j,0,15)
            rep(k,0,9) add( f[i+1][j^k] , f[i][j] );
}

int calc(int n)
{
    lint sum = 0 , x = 0;
    rep(i,1,n) sum ^= a[i];
    if ( n == 1 && a[1] < 1 ) return 0;
    red(i,n,1) {
        rep(j,0,a[i]-1)
            rep(k,0,15) sum += ( x ^ j ^ k ) * f[i-1][k];
        x ^= a[i];
        sum %= mod;
    }
    return (int)sum;
}

void init()
{
    scanf("%s",c+1);
    n = strlen( c + 1 );
    red(i,n,1) a[n+1-i] = c[i] - '0';
    a[1]--;
    rep(i,1,n-1) if ( a[i] < 0 ) a[i] += 10 , a[i+1] --;
    ans = -calc( n );
}

void work()
{
    scanf("%s",c+1);
    n = strlen( c + 1 );
    rep(i,1,n) a[n+1-i] = c[i] - '0';
    ans += calc( n );
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
}

int main()
{
    pri();
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
