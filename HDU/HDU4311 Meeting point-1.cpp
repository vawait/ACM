/*
 * Author:  vawait
 * Created Time:  2015/7/31 13:37:45
 * Problem: HDU4311 Meeting point-1
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
typedef pair < int , int >  pp;
const int maxn = 101000;
int n ; 
lint sum1[maxn] , sum2[maxn];
pp a[maxn] , b[maxn];

void init()
{
    int x , y;
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%d%d",&x,&y);
        a[i] = mp( x , y );
        b[i] = mp( y , x );
    }
    sort( a + 1 , a + n + 1 );
    sort( b + 1 , b + n + 1 );
    sum1[0] = sum2[0] = 0;
    rep(i,1,n) sum1[i] = sum1[i-1] + a[i].x , sum2[i] = sum2[i-1] + b[i].x;
}

lint calc(pp *a,lint x,lint *sum)
{
    lint l = 1 , r = n , k;
    while ( l < r ) {
        k = ( l + r + 1 ) >> 1;
        if ( a[k].x <= x ) l = k; else r = k - 1;
    }
    return l * x - sum[l] + sum[n] - sum[l] - ( n - l ) * x ;
}

void work()
{
    lint ans = 1e16;
    rep(i,1,n) ans = min( ans , calc( a , a[i].x , sum1 ) + calc( b , a[i].y , sum2 ) );
    cout << ans << endl;
}

int main()
{
    int t;
    for ( cin >> t; t; t -- ) {
        init();
        work();
    }
    return 0;
}
