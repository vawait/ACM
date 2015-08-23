/*
 * Author:  vawait
 * Created Time:  2015/8/23 15:20:26
 * Problem: HDU4390 Number Sequence
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
const lint mod = 1e9 + 7;
lint c[510][510];
int n;
map < int , int > h;
map < int , int > :: iterator it;

void init()
{
    int x , m;
    h.clear();
    rep(i,1,n) {
        scanf("%d",&x);
        m = sqrt( x * 1.0 ) + 10;
        rep(j,2,m) if ( x % j == 0 ) {
            while ( x % j == 0 ) h[j] ++ , x /= j;
        }
        if ( x > 1 ) h[x] ++;
    }
}

lint km(int n,int m)
{
    return c[n+m-1][m-1];
}

void work()
{
    if ( n == 1 ) {
        puts("1");
        return;
    }
    
    lint f[30] , x;
    rep(i,1,n) f[i] = 1;
    for ( it = h.begin(); it != h.end(); it ++ ) {
        x = it->second;
        rep(i,1,n) ( f[i] *= km( x , i ) ) %= mod;
    }
    rep(i,2,n) {
        rep(j,1,i-1) ( f[i] -= f[j] * c[i][j] ) %= mod;
    }
    f[n] %= mod;
    ( f[n] += mod ) %= mod;
    printf("%d\n",(int)f[n]);
}

int main()
{
    rep(i,0,500) c[i][0] = 1;
    rep(i,1,500)
        rep(j,1,i) c[i][j] = ( c[i-1][j] + c[i-1][j-1] ) % mod;
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
