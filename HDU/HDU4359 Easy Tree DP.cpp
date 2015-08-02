/*
 * Author:  vawait
 * Created Time:  2015/8/2 15:27:50
 * Problem: HDU4359 Easy Tree DP?
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
lint fn[500] , fw[500] , f[500][500] , C[500][500];

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

lint Cc(int n,int m)
{
    return fn[n] * fw[m] % mod * fw[n-m] % mod;
}

void init()
{
    fn[0] = fw[0] = 1;
    rep(i,1,400) fn[i] = fn[i-1] * i % mod , fw[i] = km( fn[i] , mod - 2);
    rep(i,0,400) f[0][i] = 1;
    rep(i,1,400) f[1][i] = 1;
    rep(i,0,360)
        rep(j,0,i) C[i][j] = Cc( i , j );
    rep(i,2,360) 
        rep(j,1,360) {
            f[i][j] += f[i-1][j-1] * 2 * i % mod;
            rep(k,1,i-2) {
                f[i][j] += f[k][j-1] * f[i-1-k][j-1] % mod * ( C[i-2][k] + C[i-1][k] * ( i - 1 - k ) % mod );
                f[i][j] %= mod;
            }
        }
}

void work()
{
    int T , n , m;
    cin >> T;
    rep(i,1,T) {
        scanf("%d%d\n",&n,&m);
        lint ans = f[n][m] - f[n][m-1];
        ( ans += mod ) %= mod;
        printf("Case #%d: %d\n",i,(int)ans);
    }
}

int main()
{
    init();
    work();
    return 0;
}
