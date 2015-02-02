/*
 * Author:  vawait
 * Created Time:  2015/2/2 11:18:49
 * Problem: HDU_4675
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
const int maxn = 300000;
const lint mm = 1000000007;
int n , m , K;
lint sum[maxn+10] , fn[maxn+10] , fd[maxn+10] , ans[maxn+10];

lint km(lint a,lint n)
{
    lint ans = 1;
    for ( ; n; n >>= 1 ) {
        if ( n & 1 ) ( ans *= a ) %= mm;
        ( a *= a ) %= mm;
    }
    return ans;
}

lint C(lint n,lint m)
{
    return fn[n] * ( fd[m] * fd[n-m] % mm ) % mm;
}

void init()
{
    int x;
    clr( sum , 0 );
    rep(i,1,n) scanf("%d",&x) , sum[x] ++;
}

void work()
{
    red(i,m,1) {
        int s = 0;
        ans[i] = 0;
        for ( int j = i; j <= m; j += i ) s += sum[j] , ( ans[i] -= ans[j] ) %= mm;
        if ( n - s <= K ) {
            ans[i] += C( s , K + s - n ) * km( m / i - 1 , K + s - n ) % mm * km( m / i , n - s ) % mm;
            ( ans[i] += mm ) %= mm;
        }
    }
    rep(i,1,m) printf("%I64d%c",ans[i],i==m?'\n':' ');
}

int main()
{
    fn[0] = fd[0] = 1;
    rep(i,1,maxn) fn[i] = fn[i-1] * i % mm , fd[i] = km( fn[i] , mm - 2 );
    while ( cin >> n >> m >> K ) {
        init();
        work();
    }
    return 0;
}
