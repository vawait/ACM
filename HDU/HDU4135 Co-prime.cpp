/*
 * Author:  vawait
 * Created Time:  2015/7/20 14:33:02
 * Problem: HDU4135 Co-prime
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
int sum , pri[maxn] , vis[maxn];
int m , q[maxn];
lint a , b , n;

void prime()
{
    sum = 0;
    rep(i,2,100000) if ( !vis[i] ) {
        pri[++sum] = i;
        for ( int j = i; j <= 100000; j += i ) vis[j] = 1;   
    }
}

void init()
{
    cin >> a >> b >> n;
    m = 0;
    rep(i,1,sum) {
        if ( pri[i] > n ) break;
        if ( n % pri[i] == 0 ) {
            q[++m] = pri[i];
            while ( n % pri[i] == 0 ) n /= pri[i];
        }
    }
    if ( n > 1 ) q[++m] = n;
}

void work()
{
    lint ans = b - a + 1;
    int n = ( 1 << m ) - 1;
    rep(i,1,n) {
        lint s = 0 , p = 1 , ss;
        rep(j,1,m) if ( ( i >> ( j - 1 ) & 1 ) ) p *= q[j] , s ++;
        ss = b / p - ( a - 1 ) / p;
        if ( s & 1 ) ans -= ss; else ans += ss;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    prime();
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
