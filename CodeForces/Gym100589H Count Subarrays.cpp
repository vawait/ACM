/*
 * Author:  vawait
 * Created Time:  2015/8/8 13:25:35
 * Problem: Gym100589H Count Subarrays
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
const int maxn = 101000;
lint n , m;
int a[maxn] , b[maxn];

struct bit
{
    int t[maxn];
    void cl() { clr( t , 0 ); }
    void add(int x,int y) {
        for ( ; x <= n; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
} T;

void init()
{
    rep(i,1,n) scanf("%d",&b[i]) , a[i] = b[i];
    sort( b + 1 , b + n + 1 );
    rep(i,1,n) {
        int l = 1 , r = n , k;
        while ( l < r ) {
            k = ( l + r + 1 ) >> 1;
            if ( a[i] < b[k] ) r = k - 1; else l = k;
        }
        a[i] = l;
    }
    T.cl();
}

void work()
{
    if ( !m ) {
        cout << n * ( n + 1 ) / 2 << endl;
        return;
    }
    lint p = 1 , sum = 0 , ans = 0;
    rep(i,1,n) {
        if ( i > 1 ) {
            sum -= T.sum( a[i-1] - 1 );
            T.add( a[i-1] , -1 );
        }
        while ( p <= i || p <= n && sum < m ) {
            sum += T.sum( n ) - T.sum( a[p] );
            T.add( a[p] , 1 );
            p ++;
        }
        if ( sum < m ) break;
        ans += n - p + 2;
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
