/*
 * Author:  vawait
 * Created Time:  2015/7/20 14:51:01
 * Problem: HDU4143 A Simple Problem
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
int n , ans;

void init()
{
    scanf("%d",&n);
    ans = 2e9;
}

void calc(int a,int b)
{
    if ( ( a + b ) & 1 ) return;
    int y = ( a + b ) / 2 , x = max( a , b ) - y;
    if ( x < 1 ) return;
    if ( x < ans ) ans = x;
}

void work()
{
    red(i,sqrt(n)+2,1) if ( n % i == 0 )
        calc( n / i , i );
    printf("%d\n",ans>n?-1:ans);
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
