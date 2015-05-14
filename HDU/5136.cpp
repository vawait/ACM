/*
 * Author:  vawait
 * Created Time:  2015/5/14 15:51:01
 * Problem: HDU_5136
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
const int maxn = 101000;
const lint mm = 1e9 + 7;
int n;
lint f[maxn] , sum[maxn];

lint km(lint a)
{
    lint s = 1 , n = mm - 2;
    while ( n ) {
        if ( n & 1 ) ( s *= a ) %= mm;
        ( a *= a ) %= mm;
        n >>= 1;
    }
    return s;
}

void init()
{
    f[1] = f[0] = sum[0] = 1;
    sum[1] = 2;
    rep(i,2,100000) {
        f[i] = f[i-1] * sum[i-2] % mm;
        ( f[i] += f[i-1] * ( f[i-1] + 1 ) % mm * km( 2 ) ) %= mm;
        sum[i] = ( sum[i-1] + f[i] ) % mm;
    }
}

void work()
{
    while ( scanf("%d",&n) && n ) {
        lint ans = 1 , m = f[n/2];
        if ( ( n & 1 ) && n > 1 ) {
            ans = m * ( m + 1 ) % mm * km( 2 ) % mm * sum[n/2-1] % mm;
            ( ans += m * ( m - 1 )  % mm * ( m - 2 ) % mm * km( 6 ) ) %= mm;
            ( ans += m * ( m - 1 ) ) %= mm;
            ( ans += m ) %= mm;
        } else {
            ( ans *= ( m * ( m + 1 ) % mm * km( 2 ) % mm ) ) %= mm;
        }
        ( ans += mm ) %= mm;
        cout << ans << endl;
    }
}

int main()
{
    init();
    work();
    return 0;
}
