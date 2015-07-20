/*
 * Author:  vawait
 * Created Time:  2015/7/19 13:09:48
 * Problem: BZOJ3613 [Heoi2014]南园满地堆轻絮
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
lint n , sa , sb , sc , sd , a1 , a0 , mod;

lint f(lint x)
{
    x %= mod;
    return sa * ( x * x % mod * x % mod ) + sb * ( x * x % mod ) + sc * x + sd;
}

void init()
{
    cin >> sa >> sb >> sc >> sd >> a1 >> mod;
    a0 = 0;
}

void work()
{
    lint ans = 0 , mx = a1;
    rep(i,2,n) {
        a0 = ( f( a0 ) + f( a1 ) ) % mod;
        swap( a0 , a1 );
        ans = max( ans , mx - a1 );
        mx = max( mx , a1 );
    }
    cout << ( ans + 1 ) / 2 << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
