/*
 * Author:  vawait
 * Created Time:  2015/3/29 14:56:49
 * Problem: CodeForces_328A
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
lint a[10] , b[10];

void init()
{
    rep(i,2,4) b[i] = a[i] - a[i-1];
}

void work()
{
    int v = 1;
    if ( b[2] == b[3] && b[3] == b[4] ) {
        cout << a[4] + b[4] << endl;
        return;
    }
    rep(i,1,4) if ( !a[i] ) v = 0;
    if ( v ) {
        a[5] = a[4] * a[2] / a[1];
        rep(i,2,5) if ( a[i] * a[1] != a[i-1] * a[2] ) v = 0;
    }
    if ( v ) {
        cout << a[5] << endl; 
    } else {
        puts("42");
    }
}

int main()
{
    while ( cin >> a[1] >> a[2] >> a[3] >> a[4] ) {
        init();
        work();
    }
    return 0;
}
