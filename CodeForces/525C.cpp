/*
 * Author:  vawait
 * Created Time:  2015/3/27 1:07:01
 * Problem: CodeForces_525C
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
int n , a[1010000] , f1[1010000] , f2[1010000];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    sort( a + 1 , a + 1 + n );
}

void work()
{
    lint ans = 0 , x = 0;
    red(i,n-1,1) if ( a[i+1] - a[i] <= 1 ) {
        if ( x ) ans += x * a[i] , x = 0; else x = a[i];
        i --;
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
