/*
 * Author:  vawait
 * Created Time:  2015/8/16 13:13:31
 * Problem: Gym100637J Superfactorial numeral system
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
lint n , m;

void init()
{
    rep(i,1,10000000) if ( n ) {
        n *= i;
        printf("%I64d ",n/m);
        n %= m;
    } else break;
}

void work()
{
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
