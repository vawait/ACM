/*
 * Author:  vawait
 * Created Time:  2015/7/30 12:11:17
 * Problem: HDU5328 Problem Killer
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
int n;
lint a[1001000] , b[1001000] , c[1001000];

void init()
{
    int x;
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&x) , a[i] = x;
}

lint gcd(lint x,lint y)
{
    return y ? gcd( y , x % y ) : x;
}

void work()
{
    int ans = 1 , s;
    rep(i,1,n-1) b[i] = a[i] - a[i+1];
    b[0] = b[1] - 1;
    rep(i,1,n-1) {
        if ( b[i] != b[i-1] ) s = 2; else s ++;
        ans = max( ans , s );
    }
    rep(i,1,n-1) {
        if ( !a[i] || !a[i+1] ) b[i] = c[i] = 0; else {
            lint x = gcd( a[i] , a[i+1] );
            b[i] = a[i] / x;
            c[i] = a[i+1] / x;
        }
    }
    b[0] = b[1] - 1;
    rep(i,1,n-1) {
        if ( !b[i] || b[i] != b[i-1] || c[i] != c[i-1] ) s = 2; else s ++;
        ans = max( ans , s );
    }
    printf("%d\n",ans);
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
