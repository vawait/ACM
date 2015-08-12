/*
 * Author:  vawait
 * Created Time:  2015/8/12 14:47:14
 * Problem: Gym100379H Matches are not toys for children
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
lint n;

void init()
{
    cin >> n;
    if ( n == 1 ) {
        puts("2");
        return;
    }
    lint a = 1 , b = 0 , k = 1;
    while ( k * 2 <= n ) {
        b ++;
        a += ( ( 1LL << b ) - a ) / b * b;
        if ( a == ( 1LL << b ) ) a -= b;
        k *= 2;
    }
    //printf("%lld %d\n",n,b);
    b = ( n - a ) % ( b + 1 );
    if ( b ) printf("1 %d\n",(int)b); else puts("2");
}

void work()
{
}

int main()
{
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
