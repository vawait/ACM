/*
 * Author:  vawait
 * Created Time:  2015/8/1 12:46:21
 * Problem: HDU4334 Trouble
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
int n , sum;
lint a[6][300] , q[100000] , q2[101000];

void init()
{
    scanf("%d",&n);
    rep(i,1,5)
        rep(j,1,n) scanf("%I64d",&a[i][j]);
    sum = 0;
    rep(i,1,n)
        rep(j,1,n) q[++sum] = a[1][i] + a[2][j];
    sum = 0;
    rep(i,1,n)
        rep(j,1,n) q2[++sum] = a[3][i] + a[4][j];
    sort( q + 1 , q + sum + 1 );
    sort( q2 + 1 , q2 + sum + 1 );
}

void work()
{
    lint x , y;
    rep(i,1,n) {
        int p = sum;
        x = a[5][i];
        rep(j,1,sum) {
            y = x + q2[j];
            while ( p > 1 && y + q[p] > 0 ) p --;
            if ( y + q[p] == 0 ) {
                puts("Yes");
                return;
            }
        }
    }
    puts("No");
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
