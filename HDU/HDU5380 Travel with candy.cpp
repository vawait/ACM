/*
 * Author:  vawait
 * Created Time:  2015/8/13 22:04:45
 * Problem: HDU5380 Travel with candy
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
const int maxn = 301000;
int n , m , a[maxn] , s[maxn] , b[maxn] , mx[maxn];
pair < lint , lint > q[maxn];

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    red(i,n,2) a[i] -= a[i-1];
    rep(i,0,n) scanf("%d%d",&b[i],&s[i]);
}

void work()
{
    lint ans = (lint)b[0] * m , l = n , r = n;
    q[l] = mp( b[0] , m );
    rep(i,1,n) {
        lint num = a[i];
        while ( a[i] ) {
            if ( a[i] >= q[l].y )
                a[i] -= q[l++].y;
            else
                q[l].y -= a[i] , a[i] = 0;
        }
        while ( l <= r && b[i] < q[r].x ) {
            ans -= q[r].x * q[r].y;
            num += q[r--].y;
        }
        q[++r] = mp( b[i] , num );
        ans += b[i] * num;
        num = 0;
        while ( l <= r && q[l].x <= s[i] ) num += q[l++].y;
        if ( num ) q[--l] = mp( s[i] , num );
    }
    rep(i,l,r) ans -= q[i].x * q[i].y;
    cout << ans << endl;
}

int main()
{
    int t;
    for ( cin >> t; t-- ; ) {
        init();
        work();
    }
    return 0;
}
