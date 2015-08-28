/*
 * Author:  vawait
 * Created Time:  2015/8/26 12:44:36
 * Problem: URAL1777 Anindilyakwa
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
lint n = 3 , a[100000];

void init()
{
    rep(i,1,3) cin >> a[i];
    rep(i,1,1000000) {
        sort( a + 1 , a + n + 1 );
        lint mx = 1e18;
        rep(j,1,n-1) mx = min( a[j+1] - a[j] , mx );
        if ( !mx ) {
            printf("%d\n",i);
            return;
        }
        a[++n] = mx;
    }
}

void work()
{
}

int main()
{
    init();
    work();
    return 0;
}
