/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月02日 星期日 14时47分07秒
 * File Name: HDU4038.cpp
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
const lint mm = 1e9+7;
lint  m , sum0 , sum1 , sum2 , sum3;
int n , a[201000] , s;

void init()
{
    int x = -10000000 , p;
    cin >> n >> m;
    sum0 = sum1 = sum2 = sum3 = s = 0;
    rep(i,1,n) {
        scanf("%d",&a[i]);
        if ( a[i] == 0 ) sum0 ++;
        if ( a[i] == 1 ) sum1 ++;
        if ( a[i] == 2 ) sum2 ++;
        if ( a[i] < 0 ) {
            if ( a[i] > x ) x = a[p=i]; 
            s ++;
        }
    }
    if ( s & 1 ) {
        while ( m ) {
            m --;
            if ( ( ++a[p] ) == 0 ) {
                sum0 ++;
                break;
            }
        }
    }
}

void work()
{
    lint x = min( m , sum0 ) , ans = 1;
    m -= x; sum0 -= x;
    sum1 += x;
    x = min( m , sum1 );
    m -= x; sum1 -= x;
    sum2 += x;
    x = min( m , sum2 );
    m -= x; sum2 -= x;
    sum3 += x;
    if ( m == 1 ) {
        if ( sum3 ) {
            sum3 --;
            ans = 4;
        }else {
            int x = 100000000 , p;
            rep(i,1,n) if ( a[i] > 1 && a[i] < x ) x = a[p=i];
            a[p] ++;
        }
    } else {
        if ( m % 3 == 1 ) {
            ( ans *= 4 ) %= mm;
            sum3 += ( m - 4 ) / 3;
        } else {
            sum3 += m / 3;
            m %= 3;
            if ( m ) ( ans *= m ) %= mm;
        }
    }
    x = 3;
    while ( sum3 ) {
        if ( sum3 & 1 ) ( ans *= x ) %= mm;
        ( x *= x ) %= mm;
        sum3 >>= 1;
    }
    if ( sum0 ) ans = 0;
    rep(i,1,sum2) ( ans *= 2 ) %= mm;
    rep(i,1,n) if ( a[i] > 2 || a[i] < 0 ) ( ans *= a[i] ) %= mm;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case %d: ",i);
        init();
        work();
    }
    return 0;
}
