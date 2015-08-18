/*
 * Author:  vawait
 * Created Time:  2015/8/16 20:19:03
 * Problem: Gym100637C Accounting Numeral System
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
lint n , m;

lint C(lint a,lint b)
{
    if ( a < b ) return 0;
    if ( b + b > a ) b = a - b;
    lint s = 1;
    rep(i,1,b) {
        s = s * ( a - i + 1 ) / i;
        if ( s < 0 ) return -1;
    }
    if ( s > n ) return -1;
    return s;
}

void init()
{
    int s = 0;
    while ( m -- ) {
        lint l = m , r = 1e11 , k;
        while ( l < r ) {
            k = ( l + r + 1 ) >> 1;
            if ( C( k , m + 1 ) < 0 ) r = k - 1; else l = k;
        }
        n -= C( l , m + 1 );
        cout << l << " ";
    }
}

void work()
{
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
