/*
 * Author:  vawait
 * Created Time:  2014/11/10 12:19:46
 * Problem: CodeChef_PRPALN
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
typedef unsigned long long lint;
const lint mm = 27;
int n;
lint fl[101000] , fr[101000] , fn[101000];
char a[101000];

void init()
{
    scanf("%s",a+1);
    n = strlen( a + 1 );
    fr[n+1] = fl[0] = 0;
    rep(i,1,n) fl[i] = fl[i-1] * mm + a[i] - 'a';
    red(i,n,1) fr[i] = fr[i+1] * mm + a[i] - 'a';
    fn[0] = 1;
    rep(i,1,n) fn[i] = fn[i-1] * mm;
}

bool ok(int l1,int r1,int l2,int r2)
{
    if ( r1 - l1 != r2 - l2 ) puts("k");
    return fl[r1] - fl[l1-1] * fn[r1-l1+1] == fr[l2] - fr[r2+1] * fn[r2-l2+1];
}

void work()
{
    int r , l , m = n >> 1 , v = 0;
    if ( ok( 2 , m + 1 , n - m + 1 , n ) ) v = 1;
    if ( ok( 1 , m , n - m , n - 1 ) ) v = 1;
    if ( v ) {
        puts("YES");
        return;
    }
    rep(i,2,n-1) {
        if ( i - 1 == n - i ) {
            v = ok( 1 , i - 1 , i + 1 , n );
        } else if ( i - 1 > n - i ) {
            l = n - i + 1 , r = i - 1;
            m = ( r - l + 1 ) >> 1;
            v = ok( 1 , l - 1 , i + 1 , n ) && ok( l , l + m - 1 , r - m + 1 , r );
        } else {
            l = i + 1 , r = n - ( i - 1 );
            m = ( r - l + 1 ) >> 1;
            v = ok( 1 , i - 1 , r + 1 , n ) && ok( l , l + m - 1 , r - m + 1 , r );
        }
        if ( v ) {
            puts("YES");
            return;
        }
    }
    puts("NO");
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
