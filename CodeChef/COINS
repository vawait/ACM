/*
 * Author:  vawait
 * Created Time:  2014/10/28 15:40:47
 * File Name: CodeChefCOINS.cpp
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
int n;
map < lint , lint > h;

lint f(lint t)
{
    if ( t < 4 ) return t;
    if ( h.count( t ) ) return h[t];
    return h[t] = max( t , f( t / 2 ) + f( t / 3 ) + f( t / 4 ) );
}

void init()
{
    while ( cin >> n ) cout << f( n ) << endl;
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
