/*
 * Author:  vawait
 * Created Time:  2015/4/6 22:33:41
 * Problem: CodeForces_365C
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
int n , a[10];

void init()
{
    int x;
    clr( a , 0 );
    while ( n -- ) scanf("%d",&x) , a[x] ++;
}

void work()
{
    int ans = 0 , x = min( a[1] , a[2] );
    ans += x; a[3] += x;
    a[1] -= x; a[2] -= x;
    if ( a[1] ) {
        x = a[1] / 3;
        a[3] += x;
        ans += 2 * x;
        a[1] %= 3;
        //printf("%d %d\n",a[1],ans);
        if ( a[1] <= a[3] ) ans += a[1] , a[1] = 0;
        if ( a[1] && a[4] >= 3 - a[1] ) ans += 3 - a[1] + ( a[1] > 1 ) , a[1] = 0;
    }
    if ( a[2] ) {
        x = a[2] / 3;
        a[3] += x * 2;
        ans += x * 2;
        a[2] %= 3;
        //printf("%d %d\n",a[2],ans);
        if ( a[2] == 2 ) ans += 2 , a[2] = 0;
        if ( a[2] == 1 && a[4] ) ans ++ , a[2] = 0;
        if ( a[3] >= a[2] * 2 ) ans += 2 * a[2] , a[2] = 0;
    }
    if ( a[1] || a[2] ) ans = -1;
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
