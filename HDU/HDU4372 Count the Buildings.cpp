/*
 * Author:  vawait
 * Created Time:  2015/8/5 14:02:32
 * Problem: HDU4372 Count the Buildings
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
const int maxn = 2000;
lint f[maxn+10][maxn+10] , C[maxn+10][maxn+10];

void init()
{
    f[0][0] = 1;
    rep(i,1,maxn)
        rep(j,1,i) f[i][j] = ( f[i-1][j-1] + f[i-1][j] * ( i - 1 ) ) % mod;
    rep(i,0,maxn) C[i][0] = 1;
    rep(i,1,maxn)
        rep(j,1,i) C[i][j] = ( C[i-1][j] + C[i-1][j-1] ) % mod;
}

void work()
{
    int T , N , F , B;
    scanf("%d",&T);
    while ( T -- ) {
        lint ans = 0;
        scanf("%d%d%d",&N,&F,&B);
        //rep(i,F,N-B+1) ( ans += f[i][F] * f[N-i][B-1] % mod * C[N-1][i-1] ) %= mod;
        if ( N - 1 >= F + B - 2 ) ans = f[N-1][F+B-2] * C[F+B-2][F-1] % mod;
        printf("%d\n",(int)ans);
    }
}

int main()
{
    init();
    work();
    return 0;
}
