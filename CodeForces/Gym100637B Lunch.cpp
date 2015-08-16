/*
 * Author:  vawait
 * Created Time:  2015/8/16 14:13:16
 * Problem: Gym100637B Lunch
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

int calc(int x,int y)
{
    y -= x;
    return y / 3 + y % 3;
}

void init()
{
    int n , a , b , ans = 0;
    cin >> n >> a >> b;
    if ( a == b ) {
        if ( n == 1 ) puts("0"); else puts("-1");
        return;
    }
    if ( a > b ) a = n + 1 - a , b = n + 1 - b;
    if ( b - a == 1 && a != 1 && b != n ) {
        puts("-1");
        return;
    }
    if ( a > 1 ) ans ++ , a ++;
    if ( b < n ) ans += calc( a , b - 1 ) + 1; else ans += calc( a , b );
    cout << ans << endl;
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
