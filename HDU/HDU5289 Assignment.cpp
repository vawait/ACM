/*
 * Author:  vawait
 * Created Time:  2015/7/21 12:13:53
 * Problem: HDU5289 Assignment
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
int n , m , l1 , l2 , r1 , r2 , a[maxn] , q1[maxn] , q2[maxn];

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
}

void work()
{
    lint ans = 1 , p = 0;
    if ( m == 0 ) {
        puts("0");
        return;
    }
    l1 = l2 = r1 = r2 = 1;
    q1[1] = q2[1] = 1;
    rep(i,2,n) {
        while ( l1 <= r1 && a[q1[r1]] >= a[i] ) r1 --;
        q1[++r1] = i;
        while ( l2 <= r2 && a[q2[r2]] <= a[i] ) r2 --;
        q2[++r2] = i;
        while ( abs( a[q1[l1]] - a[q2[l2]] ) >= m ) {
            p ++;
            while ( l1 <= r1 && q1[l1] <= p ) l1 ++;
            while ( l2 <= r2 && q2[l2] <= p ) l2 ++;
        }
        ans += i - p;
    }
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
