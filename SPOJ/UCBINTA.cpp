/*
 * Author:  vawait
 * Created Time:  2014/11/6 14:35:02
 * Problem: SPOJ_UCBINTA
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
int n , a[1100] , s[1010][1010];

void init()
{
    rep(i,1,n)
        rep(j,1,n) scanf("%d",&s[i][j]);
    a[1] = ( s[1][2] + s[1][3] - s[2][3] ) >> 1;
    rep(i,2,n) a[i] = s[1][i] - a[1];
    if ( n == 2 ) a[1] = 1 , a[2] = s[1][2] - 1;
}

void work()
{
    rep(i,1,n) if ( i < n ) printf("%d ",a[i]); else printf("%d\n",a[n]);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
