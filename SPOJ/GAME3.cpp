/*
 * Author:  vawait
 * Created Time:  2014/10/31 15:22:01
 * File Name: SPOJ_GAME3.cpp
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
lint t , n , v;

void init()
{
    cin >> t;
    while ( t -- ) {
        int v = 0;
        cin >> n;
        if ( n % 2 == 0 ) v = 1;
        for ( n >>= 2 ; n ; n >>= 2 ) v |= n & 1;
        puts( v ? "Marica" : "Ivica" );
    }
}

void work()
{
}

int main()
{
    init();
    work();
    return 0;
}
