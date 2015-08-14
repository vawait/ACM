/*
 * Author:  vawait
 * Created Time:  2015/8/13 12:12:26
 * Problem: HDU5387 Clock
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
typedef pair < lint , lint > pp;
pp a , b , c;

void init()
{
    int x , y , z;
    scanf("%d%*c%d%*c%d",&x,&y,&z);
    c.x = z;
    c.y = 60;
    b.y = 3600;
    b.x = y * 60 + z;
    if ( x >= 12 ) x -= 12;
    a.y = 3600 * 12;
    a.x = x * 3600 + y * 60 + z;
}

lint gcd(lint x,lint y)
{
    return y ? gcd( y , x % y ) : x;
}

void calc(pp a, pp b)
{
    a.x *= b.y;
    a.x -= b.x * a.y; 
    a.y *= b.y;
    if ( a.x < 0 ) a.x = -a.x;
    a.x *= 360;
    if ( a.x > 180 * a.y ) a.x = 360 * a.y - a.x;
    lint x = gcd( a.x , a.y );
    if ( a.x == 0 ) printf("0 "); else  {
        a.x /= x; a.y /= x;
        if ( a.y == 1 ) printf("%I64d ",a.x); else
            printf("%I64d/%I64d ",a.x,a.y);
    }
}

void work()
{
    calc( a , b );
    calc( a , c );
    calc( b , c );
    puts("");
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
