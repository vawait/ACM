/*
 * Author:  vawait
 * Created Time:  2015/7/31 19:51:56
 * Problem: HDU4315 Climbing the Hill
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
int n , m , a[1100];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    a[0] = -1;
}

void work()
{
    int sg = 0;
    if ( m == 1 ) {
        puts("Alice");
        return;
    }
    if ( m == 2 && ( n & 1 ) ) a[1] --;
    for ( int i = n; i > 0; i -= 2 ) sg ^= a[i] - a[i-1] - 1;
    if ( sg ) puts("Alice"); else puts("Bob");
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
