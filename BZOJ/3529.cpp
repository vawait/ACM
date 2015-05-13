/*
 * Author:  vawait
 * Created Time:  2015/5/13 20:45:03
 * Problem: BZOJ_3529
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
int N[maxn] , M[maxn] , A[maxn] , ans[maxn];
pair < int , int > ask[maxn] , f[maxn+10];

struct bit
{
    int t[maxn+10];
    void add(int x,int y) {
        for ( ; x <= maxn; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
} T;

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
    rep(i,1,maxn) {
        f[i].y = i;
        for ( int j = i; j <= maxn; j += i ) f[j].x += i;
    }
}

int sum(int a,int b)
{
    int ans = 0 , p;
    if ( a > b ) swap( a , b );
    for ( int i = 1; i <= a; i = p + 1 ) {
        p = min( a / ( a / i ) , b / ( b / i ) );
        ans += ( a / i ) * ( b / i ) * ( T.sum( p ) - T.sum( i - 1 ) );
    }
    return ans&((1LL<<31)-1);
}

void work()
{
    int Q , p = 1;
    scanf("%d",&Q);
    rep(i,1,Q) scanf("%d%d%d",&N[i],&M[i],&A[i]) , ask[i] = mp( A[i] , i );
    sort( ask + 1 , ask + Q + 1 );
    sort( f + 1 , f + maxn + 1 );
    
    rep(i,1,Q) {
        while ( p <= maxn && f[p].x <= ask[i].x ) {
            for ( int j = f[p].y; j <= maxn; j += f[p].y )
                T.add( j , mobius[j/f[p].y] * f[p].x );
            p ++;
        }
        ans[ask[i].y] = sum( N[ask[i].y] , M[ask[i].y] );
    }
    
    rep(i,1,Q) printf("%d\n",ans[i]);
}

int main()
{
    init();
    work();
    return 0;
}
