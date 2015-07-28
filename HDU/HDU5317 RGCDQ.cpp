/*
 * Author:  vawait
 * Created Time:  2015/7/28 12:25:55
 * Problem: HDU5317 RGCDQ
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
const int maxn = 1001000;
const int mx = 10;
int sum[11][maxn] , f[maxn];
int sum_prime , prime[maxn+10];
bool visit[maxn];

void pri()
{
    sum_prime = 0;
    rep(i,2,1000000) {
        if ( !visit[i] ) prime[++sum_prime] = i , f[i] = 1;
        for ( int j = 1; j <= sum_prime && i * prime[j] <= 1000000; j++ ) {
            visit[i*prime[j]] = 1;
            f[i*prime[j]] = f[i] + bool( i % prime[j] );
        }
    }
}

void init()
{
    pri();
    rep(i,1,mx)
        rep(j,1,1000000) sum[i][j] = sum[i][j-1] + ( f[j] % i == 0 );
}

void work()
{
    int T , l , r , ans;
    for ( cin >> T; T; T -- ) {
        ans = 0;
        scanf("%d%d",&l,&r);
        rep(i,1,mx) if ( sum[i][r] - sum[i][l-1] > 1 ) ans = i;
        printf("%d\n",ans);
    }
}

int main()
{
    init();
    work();
    return 0;
}
