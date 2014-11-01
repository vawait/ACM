/*
 * Author:  vawait
 * Created Time:  2014/11/1 13:04:35
 * Problem: SPOJ_KSEQ.cpp
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
int x , y , z;

void init()
{
    scanf("%d%d%d",&x,&y,&z);
}

void work()
{
    lint ans = 0 , b , c;
    b = sqrt( 2.0 * x );
    while ( b * ( b - 1 ) < 2 * x ) b ++;
    if ( b < 2 ) b = 2;
    if ( !y && !z ) {
        while ( b * ( b - 1 ) > 2 * x ) b --;
        if ( b * ( b - 1 ) == 2 * x ) ans = 3;
    } else if ( z ) {
        red(i,b,1) if ( z % i == 0 ) {
            c = z / i;
            b = y / ( i + c );
            if ( b * ( i + c ) == y && i * ( i - 1 ) + b * ( b - 1 ) + c * ( c - 1 ) == 2 * x ) ans ++;
        }
    } else {
        red(i,b,1) if ( y % i == 0 ) {
            b = y / i;
            if ( i * ( i - 1 ) + b * ( b - 1 ) == 2 * x ) ans += 2;
        }
    }
    printf("%lld\n",ans);
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
