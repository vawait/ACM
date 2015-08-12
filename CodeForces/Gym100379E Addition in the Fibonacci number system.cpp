/*
 * Author:  vawait
 * Created Time:  2015/8/12 13:29:43
 * Problem: Gym100379E Addition in the Fibonacci number system
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
int n , a[10100];
char c[10100];

void init()
{
    int len;
    clr( a , 0 );
    scanf("%s",c+1);
    n = len = strlen( c + 1 );
    rep(i,1,len) if ( c[i] == '1' ) a[len-i+1] ++;
    scanf("%s",c+1);
    len = strlen( c + 1 );
    rep(i,1,len) if ( c[i] == '1' ) a[len-i+1] ++;
    n = max( len , n );
}

void work()
{
    int ok = 1;
    while ( ok ) {
        ok = 0;
        red(i,n,0) if ( a[i] ) {
            if ( i > 1 && a[i-1] ) {
                a[i+1] ++;
                a[i] --;
                a[i-1] --;
                ok = 1;
            }
            if ( a[i] > 1 ) {
                a[i+1] ++;
                if ( i > 1 ) a[i-2] ++;
                a[i] -= 2;
                ok = 1;
            }
        }
        red(i,n+10,n) if ( a[i] ) {
            n = i;
            break;
        }
    }
    if ( a[0] ) a[1] ++;
    while ( n > 1 && !a[n] ) n --;
    red(i,n,1) printf("%d",a[i]);
}

int main()
{
    init();
    work();
    return 0;
}
