/*
 * Author:  vawait
 * Created Time:  2015/8/16 13:28:58
 * Problem: Gym100637A Nano alarm-clocks
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
typedef unsigned long long lint;
lint n , a[201000] , f1[201000] , f2[201000];

void init()
{
    int x;
    rep(i,1,n) {
        a[i] = 0;
        rep(j,1,3) {
            scanf("%d",&x);
            a[i] = a[i] * 1000000 + x;
        }
    }
    sort( a + 1 , a + n + 1 );
    f1[1] = 0;
    rep(i,2,n) f1[i] = f1[i-1] + ( i - 1 ) * ( a[i] - a[i-1] );
    f2[n+1] = 0;
    lint t = 12 * sqr( lint( 1000000 ) );
    red(i,n,1) f2[i] = f2[i+1] + ( a[i] ? t - a[i] : 0 );
}

void work()
{
    lint ans = f2[1];
    rep(i,1,n) ans = min( ans , f1[i] + f2[i+1] + ( n - i ) * a[i] );
    lint x = ans % 1000000 , y;
    ans /= 1000000;
    y = ans % 1000000;
    ans /= 1000000;
    cout << ans << " " << y << " " << x << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
