/*
 * Author:  vawait
 * Created Time:  2015/1/31 14:48:18
 * Problem: HDU_4746
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
const int maxn = 500000;
int sum_prime , visit[maxn+10] , prime[maxn+10] , mobius[maxn+10];
int sum[maxn+10][21] , sp[maxn+10];

void init()
{
    sum_prime = 0;
    mobius[1] = 1;
    rep(i,2,maxn) {
        if ( !visit[i] ) {
            prime[++sum_prime] = i; 
            mobius[i] = -1;
            sp[i] = 1;
        }
        for ( int j = 1; j <= sum_prime && i * prime[j] <= maxn; j ++ ) {
            visit[i*prime[j]] = 1;
            sp[i*prime[j]] = sp[i] + 1;
            if ( i % prime[j] ) mobius[i*prime[j]] = -mobius[i]; else break;
        }
    }
    rep(i,1,maxn)
        for ( int j = i; j <= maxn; j += i ) sum[j][sp[i]] += mobius[j/i];
    rep(i,1,maxn)
        rep(j,1,19) sum[i][j] += sum[i][j-1];
    rep(i,1,maxn)
        rep(j,0,19) sum[i][j] += sum[i-1][j];
}

void work()
{
    int Q , n , m , p;
    for ( cin >> Q; Q; Q -- ) {
        lint ans = 0 , pos;
        scanf("%d%d%d",&n,&m,&p);
        p = min( p , 19 );
        if ( n > m ) swap( n , m );
        for ( lint i = 1 ; i <= n; i = pos + 1 ) {
            pos = min( n / ( n / i ) , m / ( m / i ) );
            ans += ( n / i ) * ( m / i ) * ( sum[pos][p] - sum[i-1][p] );
        }
        printf("%I64d\n",ans);
    }
}

int main()
{
    init();
    work();
    return 0;
}
