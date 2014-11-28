/*
 * Author:  vawait
 * Created Time:  2014/11/28 13:02:46
 * Problem: SPOJ_VLATTICE
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
#define sqr(x) ((x) * (x))
typedef long long lint;
const int maxn = 1000000;
int sum_prime , visit[maxn+10] , prime[maxn+10] , mobius[maxn+10];

void init()
{
    sum_prime = 0;
    mobius[1] = 1;
    rep(i,2,maxn) {
        if ( !visit[i] ) prime[++sum_prime] = i , mobius[i] = -1;
        for ( int j = 1; j <= sum_prime && i * prime[j] <= maxn ; j ++ ) {
            visit[i*prime[j]] = 1;
            if ( i % prime[j] ) mobius[i*prime[j]] = -mobius[i]; else break;
        }
    }
}

void work()
{
    lint n;
    scanf("%lld",&n);
    lint ans = 3;
    rep(i,1,n) if ( mobius[i] ) 
        ans += mobius[i] * sqr( n / i ) * ( n / i + 3 );
    printf("%lld\n",ans);
}

int main()
{
    int t;
    init();
    for ( cin >> t; t; t-- ) work();
    return 0;
}
