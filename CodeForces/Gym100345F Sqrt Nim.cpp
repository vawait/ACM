/*
 * Author:  vawait
 * Created Time:  2015/8/29 12:51:12
 * Problem: Gym100345F Sqrt Nim
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
lint n;

void init()
{
}

void work()
{
    lint p = 0;
    rep(i,1,1000000) {
        if ( sqr( i ) > n ) {
            n = abs( p - n );
            if ( n % i ) puts("WIN"); else puts("LOSE");
            return;
        }
        p += ( sqr( i ) - 1 - p ) / ( i ) * ( i );
        if ( p < sqr( i ) ) p += i + 1;
    }
}

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}

