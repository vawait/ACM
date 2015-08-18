/*
 * Author:  vawait
 * Created Time:  2015/8/18 13:31:33
 * Problem: HDU5396 Expression
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
int n , a[200];
char op[200];
lint c[110][110] , f[110][110] , fn[200];

void init()
{
    rep(i,0,n) c[i][0] = 1;
    rep(i,1,n)
        rep(j,1,i) c[i][j] = ( c[i-1][j] + c[i-1][j-1] ) % mod;
    clr( f , 0 );
    rep(i,1,n) scanf("%I64d",&f[i][i]);
    scanf("%s",op+1);
    fn[0] = 1;
    rep(i,1,110) fn[i] = fn[i-1] * i % mod;
}

lint calc(lint x,lint y,char c)
{
    if ( c == '-' ) return x - y;
    if ( c == '+' ) return x + y;
    return x * y % mod;
}

void work()
{
    rep(len,1,n-1)
        rep(i,1,n-len) {
            int j = i + len;
            rep(k,i,j-1) {
                if ( op[k] == '*' ) {
                    ( f[i][j] += calc( f[i][k] , f[k+1][j] , op[k] ) * c[j-i-1][k-i] ) %= mod;
                } else {
                    ( f[i][j] += calc( f[i][k] * fn[j-k-1] % mod , f[k+1][j] * fn[k-i] % mod , op[k] ) * c[j-i-1][k-i] ) %= mod;
                }
            }
        }
    lint ans = f[1][n];
    ans %= mod;
    ( ans += mod ) %= mod;
    cout << ans << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
