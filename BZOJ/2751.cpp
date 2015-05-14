/*
 * Author:  vawait
 * Created Time:  2015/5/14 23:06:30
 * Problem: BZOJ_2751
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
const lint mm = 1e9 + 7;
lint n , m , k , ans , num;
pair < int , int > a[101000];

void init()
{
    int p = 1;
    ans = 1;
    num = 0;
    rep(i,1,k) scanf("%d%d",&a[i].x,&a[i].y);
    sort( a + 1 , a + k + 1 );
    while ( p <= k ) {
        int i = p;
        lint sum = m * ( m + 1 ) / 2;
        while ( p <= k && a[i].x == a[p].x ) {
            if ( a[p] != a[p-1] ) sum -= a[p].y;
            p ++;
        }
        ( ans *= sum % mm ) %= mm;
        num ++;
    }
}

void work()
{
    if ( n < num ) ans = 0;
    m = m * ( m + 1 ) / 2 % mm;
    for ( n -= num; n; n >>= 1 ) {
        if ( n & 1 ) ( ans *= m ) %= mm;
        ( m *= m ) %= mm;
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> m >> n >> k ) {
        init();
        work();
    }
    return 0;
}
