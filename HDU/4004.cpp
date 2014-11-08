/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月08日 星期六 13时00分28秒
 * File Name: HDU_4004
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define db pop_back
typedef long long lint;
int n , L , m , a[501000];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    a[++n] = 0; a[++n] = L;
    sort( a + 1 , a + n + 1 );
}

int ok(int k)
{
    int x = 1 , y;
    rep(i,1,m) {
        y = a[x];
        while ( x < n && a[x+1] - y <= k ) x ++;
        if ( x == n ) return 1;
    }
    return 0;
}

void work()
{
    int l = 1 , r = L , k;
    while ( l < r ) {
        k = ( l + r ) >> 1;
        if ( ok( k ) ) r = k; else l = k + 1;
    }
    printf("%d\n",l);
}

int main()
{
    while ( cin >> L >> n >> m ) {
        init();
        work();
    }
    return 0;
}
