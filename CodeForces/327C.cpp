/*
 * Author:  vawait
 * Created Time:  2015/3/29 12:40:11
 * Problem: CodeForces_327C
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
const lint mm = 1000000007;
int n , m;
char a[201000];

void init()
{
    scanf("%d",&m);
    n = strlen( a + 1 );
}

lint km(lint a,lint n)
{
    lint s = 1;
    for ( ; n; n >>= 1 ) {
        if ( n & 1 ) ( s *= a ) %= mm;
        ( a *= a ) %= mm;
    }
    return s;
}

void work()
{
    lint ans = 0;
    if ( n == 1 ) {
        if ( a[1] == '0' || a[1] == '5' )
            ans = km( 2 , m ) - 1;
    } else {
        rep(i,1,n) if ( a[i] == '0' || a[i] == '5' )
            ( ans += km( 2 , i - 1 ) * ( km( 2 , (lint)n * m ) - 1 + mm ) ) %= mm;
        ( ans *= km( ( km( 2 , n ) - 1 + mm ) % mm , mm - 2 ) ) %= mm;
    }
    cout << ( ans + mm ) % mm << endl;
}

int main()
{
    while ( scanf("%s",a+1) != EOF ) {
        init();
        work();
    }
    return 0;
}
