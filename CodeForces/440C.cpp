/*
 * Author:  vawait
 * Created Time:  2015/2/23 13:56:12
 * Problem: test.cpp
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
lint n , a[20];

void init()
{
    a[0] = 0;
    rep(i,1,16) a[i] = a[i-1] * 10 + 1;
}

lint dfs(lint n,int m)
{
    if ( n < 0 ) n = -n;
    if ( !n ) return 0;
    if ( m == 1 ) return n;
    lint k = n / a[m];
    lint ans = min( dfs( n - k * a[m] , m - 1 ) + k * m , dfs( ( k + 1 ) * a[m] - n , m - 1 ) + ( k + 1 ) * m );
    //if ( k ) ans = min( (lint)ans , dfs( n - ( k - 1 ) * a[m] , m - 1 ) + ( k - 1 ) * m );
    return ans;
}

void work()
{
    cout << dfs(n,16) << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
