/*
 * Author:  vawait
 * Created Time:  2015/2/28 14:22:01
 * Problem: CodeForces_398A
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
#define rep(i, a, b) for (lint i = (a); i <= (b); ++i)
#define red(i, a, b) for (lint i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x) * (x))
typedef long long lint;
lint a , b , ans , p;

void init()
{
    ans = -sqr( 1000000000LL );
}

void work()
{
    if ( b <= 1 || a < 1 ) {
        cout << sqr( a ) - sqr( b ) << endl;
        rep(i,1,a) printf("o");
        rep(i,1,b) printf("x");
        puts("");
        return ;
    }
    red(i,min(b-1,a),1) {
        lint sum = sqr( a + 1 - i ) + i - 1 , x = b % ( i + 1 ) , y = b / ( i + 1 );
        sum -= x * sqr( y + 1 ) + ( i + 1 - x ) * sqr( y );
        if ( sum > ans ) ans = sum , p = i;
    }
    lint x = b % ( p + 1 ) , y = b / ( p + 1 );
    cout << ans << endl;
    rep(i,1,2*p+1) if ( i & 1 ) {
        lint ss = y;
        if ( x ) ss ++ , x --;
        rep(j,1,ss) printf("x");
    } else {
        lint ss = 1;
        if ( i == 2 ) ss = a - p + 1;
        rep(j,1,ss) printf("o");
    }
    puts("");
}

int main()
{
    while ( cin >> a >> b ) {
        init();
        work();
    }
    return 0;
}
