/*
 * Author:  vawait
 * Created Time:  2015/8/22 15:02:09
 * Problem: Aizu2556 Integer in Integer
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
const int maxn = 101000;
const lint mod = 1e9 + 7;
lint fn[maxn] , f[maxn] , f2[maxn];
int l1 , l2 , m , a[maxn] , b[maxn] , c[maxn];
char sa[maxn] , sb[maxn] , sc[maxn];

void init()
{
    clr( a , 0 );
    clr( b , 0 );
    scanf("%s",sb+1);
    scanf("%s",sc+1);
    l1 = strlen( sa + 1 );
    rep(i,1,l1) a[i] = sa[l1+1-i] - '0';
    l2 = strlen( sb + 1 );
    rep(i,1,l2) b[i] = sb[l2+1-i] - '0';
    m = strlen( sc + 1 );
    rep(i,1,m) c[i] = sc[m+1-i] - '0';
    fn[0] = 1;
    rep(i,1,100000) fn[i] = fn[i-1] * 10 % mod;
    a[1] --;
    rep(i,1,l1) if ( a[i] < 0 ) a[i+1] -- , a[i] += 9;
}

int big(int *a,int n)
{
    red(i,m,1) {
        if ( a[n] > c[i] ) return 1;
        if ( a[n] < c[i] ) return -1;
        n --;
    }
    return 0;
}

lint calc(int *a,int n)
{
    if ( a[n] < 0 || a[n+1] < 0 ) return 0;
    
    int zero = ( m == 1 && !c[m] );
    lint ans = 0;
    while ( n > 1 && !a[n] ) n --;
    f2[0] = f[n+1] = 0;
    red(i,n,1) f[i] = ( f[i+1] * 10 + a[i] ) % mod;
    rep(i,1,n) f2[i] = ( a[i] * fn[i-1] + f2[i-1] ) % mod;
    
    red(i,n,m) {
        ( ans += f[i+1] * fn[i-m] ) %= mod;
        //printf("%d %lld\n",i,ans);
        if ( zero && i != n && i != 1 ) ans -= fn[i-m];
        if ( zero && i != 1 && i == n ) continue;
        int x = big( a , i );
        //printf("%d %lld\n",i,ans);
        if ( x == 0 ) ans += f2[i-m] + 1;
        if ( x == 1 ) ans += fn[i-m];
    }
    
    ans %= mod;
    ( ans += mod ) %= mod;
    return ans;
}

void work()
{
    int ans = calc( b , l2 ) - calc( a , l1 );
    ( ans += mod ) %= mod;
    printf("%d\n",ans);
}

int main()
{
    while ( scanf("%s",sa+1) != EOF ) {
        init();
        work();
    }
    return 0;
}
