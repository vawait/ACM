/*
 * Author:  vawait
 * Created Time:  2015/1/28 18:54:22
 * Problem: SPOJ_PGCD
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
const int maxn = 1e7;
int sum_prime , visit[maxn+10] , prime[maxn+10] , mobius[maxn+10];
int sum[maxn+10];

void init()
{
    sum_prime = 0;
    mobius[1] = 1;
    rep(i,2,maxn) {
        if ( !visit[i] ) prime[++sum_prime] = i , mobius[i] = -1;
        for ( int j = 1; j <= sum_prime && i * prime[j] <= maxn; j++ ) {
            visit[i*prime[j]] = 1;
            if ( i % prime[j] ) mobius[i*prime[j]] = -mobius[i]; else break;
        }
    }
    rep(i,2,maxn) if ( !visit[i] ) {
        for ( int j = 1; j * i <= maxn; j ++ ) sum[j*i] += mobius[j];
    }
    rep(i,2,maxn) sum[i] += sum[i-1];
}

void work()
{
    lint T , a , b , p;
    for ( cin >> T; T; T -- ) {
        lint ans = 0;
        cin >> a >> b;
        if ( a > b ) swap( a , b );
        for ( int i = 1; i <= a; i = p + 1 ) {
            p = min( a / ( a / i ) , b / ( b / i ) );
            ans += ( a / i ) * ( b / i ) * ( sum[p] - sum[i-1] );
        }
        cout << ans << endl;
    }
}

int main()
{
    init();
    work();
    return 0;
}
