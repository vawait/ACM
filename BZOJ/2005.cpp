/*
 * Author:  vawait
 * Created Time:  2015/1/30 9:59:26
 * Problem: BZOJ_2005
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
int mx , n , m;

void init()
{
    scanf("%d%d",&n,&m);
    mx = max( n , m );
    sum_prime = 0;
    mobius[1] = 1;
    rep(i,2,mx) {
        if ( !visit[i] ) prime[++sum_prime] = i , mobius[i] = -1;
        for ( int j = 1; j <= sum_prime && i * prime[j] <= mx; j ++ ) {
            visit[i*prime[j]] = 1;
            if ( i % prime[j] ) mobius[i*prime[j]] = -mobius[i]; else break;
        }
    }
    rep(i,2,mx) mobius[i] += mobius[i-1];
}

lint ask(lint a,lint b)
{
    lint ans = 0 , p;
    if ( a > b ) swap( a , b );
    for ( int i = 1; i <= a; i = p + 1 ) {
        p = min( a / ( a / i ) , b / ( b / i ) );
        ans += ( a / i ) * ( b / i ) * ( mobius[p] - mobius[i-1] );
    }
    return ans;
}

void work()
{
    lint ans = 0;
    red(i,min(n,m),1) ans += ask( n / i , m / i ) * ( 2 * i - 1 );
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
