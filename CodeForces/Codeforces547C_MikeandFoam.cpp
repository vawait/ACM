/*
 * Author:  vawait
 * Created Time:  2015/5/27 1:24:08
 * Problem: Codeforces547C Mike and Foam
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
int n , q , num , a[maxn+10] , sum[maxn+10] , use[maxn+10];
int sum_prime , visit[maxn+10] , prime[maxn+10] , mobius[maxn+10];
lint ans = 0;
vector < int > g[maxn+10];

void pri()
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
    rep(i,2,maxn) if ( mobius[i] != 0 )
        for ( int j = i; j <= maxn; j += i ) g[j].pb( i );
}

void init()
{
    pri();
    scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
}

void add(int x)
{
    int y;
    ans += num;
    red(i,g[x].size()-1,0) {
        y = g[x][i];
        ans += mobius[y] * sum[y];
        sum[y] ++;
    }
    num ++;
}

void del(int x)
{
    int y;
    num --;
    ans -= num;
    red(i,g[x].size()-1,0) {
        y = g[x][i];
        sum[y] --;
        ans -= mobius[y] * sum[y];
    }
}

void work()
{
    int x;
    while ( q -- ) {
        scanf("%d",&x);
        if ( use[x] ) 
            del( a[x] ) , use[x] = 0;
        else
            add( a[x] ) , use[x] = 1;
        printf("%I64d\n",ans);
    }
}

int main()
{
    init();
    work();
    return 0;
}