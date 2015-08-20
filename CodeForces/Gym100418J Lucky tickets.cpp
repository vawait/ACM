/*
 * Author:  vawait
 * Created Time:  2015/8/19 15:01:57
 * Problem: Gym100418J Lucky tickets
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
lint n , f[71][71][71] , a[80] , ans = 0;

void init()
{
    cin >> n;
    lint s = n;
    rep(i,1,70) a[i] = s & 1 , s >>= 1;
}

void calc(lint mod)
{
    clr( f , 0 );
    f[0][0][0] = 1;
    rep(i,0,69)
        rep(j,0,mod) 
            rep(k,0,mod) if ( f[i][j][k] ) {
                f[i+1][j][(k<<1)%mod] += f[i][j][k];
                f[i+1][j+1][(k<<1|1)%mod] += f[i][j][k];
            }
    lint s = 0 , s1 = 0;
    red(i,70,1) {
        s = ( s << 1 ) % mod;
        if ( a[i] ) {
            lint x = s;
            rep(j,1,i-1) ( x *= 2 ) %= mod;
            ans += f[i-1][mod-s1][(mod-x)%mod];
            s1 ++;
            ( s += 1 ) %= mod;
            if ( s1 == mod ) {
                lint x = s;
                rep(j,1,i-1) ( x *= 2 ) %= mod;
                ans += f[i-1][mod-s1][(mod-x)%mod];
                return;
            }
        }
    }
}

void work()
{
    rep(i,1,70) calc( i );
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
