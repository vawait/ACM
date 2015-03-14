/*
 * Author:  vawait
 * Created Time:  2015/3/14 15:39:19
 * Problem: SGU_137
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
int n , m , a[2010];

void init()
{
}

int ok(int k)
{
    int x = k , y;
    a[k] = 1; a[0] = 0;
    rep(i,3,n) {
        y = ( k + x ) % n;
        a[y] = a[x] - ( x == n - 1 );
        x = y;
    }
    
    rep(i,0,n-1) {
        y = ( i - k + n ) % n;
        if ( y == 0 && a[i] - 1 != a[0] ) return 0;
        if ( y == n - 1 && a[i] + 1 != a[n-1] ) return 0;
        if ( y && y < n - 1 && a[i] != a[y] ) return 0;
    }
    
    int s = m;
    rep(i,0,n-1) s -= a[i];
    if ( s % n ) return 0;
    s /= n;
    rep(i,0,n-1) a[i] += s;
    rep(i,0,n-1) if ( a[i] < 0 ) return 0;
    
    return 1;
}

void work()
{
    rep(i,1,n-1) if ( ok( i ) ) {
        rep(i,0,n-1) printf("%d ",a[i]);
        return;
    }
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
