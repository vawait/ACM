/*
 * Author:  vawait
 * Created Time:  2014/10/31 13:42:18
 * File Name: SPOJ_GSWORDS.cpp
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
const lint mm = 1e9 + 7;
lint n;

struct nodd
{
    lint a[4][4];
    void cl() { clr( a , 0 ); }
} a , b , c;

void km(nodd &a,nodd &b)
{
    c.cl();
    rep(k,1,3)
        rep(i,1,3)
            rep(j,1,3) ( c.a[i][j] += a.a[i][k] * b.a[k][j] ) %= mm;
    a = c;
}

void init()
{
    a.cl();
    b.cl();
    a.a[1][2] = 1;
    b.a[3][1] = 1;
    b.a[1][2] = 1;
    b.a[2][2] = 1;
    b.a[2][3] = 1;
}

void work()
{
    while ( n ) {
        if ( n & 1 ) km( a , b );
        km( b , b );
        n >>= 1;
    }
    cout << ( a.a[1][1] + a.a[1][2] + a.a[1][3] ) % mm << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
