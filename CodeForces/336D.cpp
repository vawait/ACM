/*
 * Author:  vawait
 * Created Time:  2015/2/27 13:26:18
 * Problem: CodeForces_336D
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
const int mm = 1000000007;
int n , m , g;
lint f[201000] , fn[201000];

lint km(lint a,lint n)
{
    lint s = 1;
    for ( ; n; n >>= 1 ) {
        if ( n & 1 ) ( s *= a ) %= mm;
        ( a *= a ) %= mm;
    }
    return s;
}

void init()
{
    f[0] = fn[0] = 1;
    rep(i,1,n+m) f[i] = f[i-1] * i % mm , fn[i] = km( f[i] , mm - 2 );
}

lint dfs(int n,int m,int g)
{
    if ( n + m == 1 ) return g ? m : n;
    lint ans = 0;
    if ( g ) {
        if ( n ) return dfs( n - 1 , m , 0 );
    } else {
        if ( m ) ans = f[n+m-1] * fn[n] % mm * fn[m-1] % mm;
        if ( n ) ( ans += dfs( n - 1 , m , 1 ) ) %= mm; 
        return ans;
    }
    return ans;
}

void work()
{
    cout << dfs( n , m , g ) << endl;
}

int main()
{
    while ( cin >> n >> m >> g ) {
        init();
        work();
    }
    return 0;
}
