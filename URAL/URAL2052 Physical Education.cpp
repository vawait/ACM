/*
 * Author:  vawait
 * Created Time:  2015/8/25 15:17:18
 * Problem: URAL2052 Physical Education
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
int n , sum[110] , a[20];
lint f[20][110];

int dig(int x)
{
    int s = 0;
    while ( x ) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

lint calc(int n,int s)
{
    lint ans = ( dig( n ) == s );
    rep(i,1,10) a[i] = n % 10 , n /= 10;
    red(i,10,1) {
        rep(j,0,a[i]-1) if ( j <= s ) ans += f[i-1][s-j];
        s -= a[i];
        if ( s < 0 ) break;
    }
    return ans;
}

void init()
{
    f[0][0] = 1;
    rep(i,0,10)
        rep(j,0,100)
            rep(k,0,9) f[i+1][j+k] += f[i][j];
    
    scanf("%d",&n);
    rep(i,1,100) sum[i] = sum[i-1] + calc( n , i );
}

void work()
{
    int ans = 0;
    rep(i,1,100) {
        int l = 1 , r = n , mid;
        while ( l < r ) {
            mid = ( l + r + 1 ) >> 1;
            if ( calc( mid , i ) + sum[i-1] >= mid ) l = mid; else r = mid - 1;
        }
        if ( dig( l ) == i && calc( l , i ) + sum[i-1] == l ) ans ++;
    }
    printf("%d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
