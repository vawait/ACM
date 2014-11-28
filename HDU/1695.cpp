/*
 * Author:  vawait
 * Created Time:  2014/11/28 13:02:46
 * Problem: HDU_1695
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
const int maxn = 100000;
int sum_prime , visit[maxn+10] , prime[maxn+10] , mobius[maxn+10];
int a , b , k;

void init()
{
    sum_prime = 0;
    mobius[1] = 1;
    rep(i,2,maxn) {
        if ( !visit[i] ) prime[++sum_prime] = i , mobius[i] = -1;
        for ( int j = 1; j <= sum_prime && i * prime[j] <= maxn ; j ++ ) {
            visit[i*prime[j]] = 1;
            if ( i % prime[j] ) mobius[i*prime[j]] = -mobius[i]; else {
                mobius[i*prime[j]] = 0;
                break;
            }
        }
    }
}

void work()
{
    scanf("%*d%d%*d%d%d",&a,&b,&k);
    if ( !k ) {
        puts("0");
        return;
    }
    a /= k; b /= k;
    lint ans = 0 , sum = 0 , mx = min( a , b );
    red(i,min(a,b),1) if ( mobius[i] ) {
        ans += (lint)mobius[i] * ( a / i ) * ( b / i );
        sum += mobius[i] * sqr( mx / i );
    }
    ans -= sum >> 1;
    printf("%I64d\n",ans);
}

int main()
{
    int t;
    cin >> t;
    init();
    rep(i,1,t) {
        printf("Case %d: ",i);
        work();
    }
    return 0;
}
