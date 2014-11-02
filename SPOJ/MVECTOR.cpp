/*
 * Author:  vawait
 * Created Time:  2014/11/2 17:59:10
 * Problem: SPOJ_MVECTOR.cpp
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

struct Point {
    lint x , y;
	Point(){}
	Point(lint x, lint y) : x(x) , y(y) {}
	Point operator + (const Point &b) { return Point( x + b.x , y + b.y ); }
	Point operator - (const Point &b) { return Point( x - b.x , y - b.y ); }
	lint operator * (const Point &b) const { return x * b.y - y * b.x; }
	lint len() { return x * x + y * y; }
	bool operator < (const Point &b) const { return atan2( y, x ) > atan2( b.y , b.x ); }
} a[61000] , s[61000];

void init()
{
    rep(i,1,n) scanf("%lld%lld",&a[i].x,&a[i].y);
    sort( a + 1 , a + 1 + n );
    rep(i,1,n) a[i+n] = a[i];
    rep(i,1,n+n) s[i] = a[i] + s[i-1];
}

void work()
{
    lint ans = 0 , r = 1;
    rep(i,1,n) {
        ans = max( ans , ( s[r] - s[i-1] ).len() );
        while ( r + 1 < i + n && a[i] * a[r+1] <= 0 ) ans = max( ans , ( s[++r] - s[i-1] ).len() );
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
