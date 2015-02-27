/*
 * Author:  vawait
 * Created Time:  2015/2/23 13:34:50
 * Problem: test.cpp
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
lint n , s , a[51000];

void init()
{
    s = 0;
    rep(i,1,n) scanf("%I64d",&a[i]) , s += a[i];
    s /= n;
    rep(i,1,n) a[i] -= s;
}

void work()
{
    lint ans = 0;
    rep(i,1,n) if ( a[i] > 0 ) {
        ans += a[i];
        a[i+1] += a[i];
    } else {
        ans -= a[i];
        a[i+1] += a[i];
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
