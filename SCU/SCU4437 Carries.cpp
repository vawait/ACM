/*
 * Author:  vawait
 * Created Time:  2015/10/6 13:37:43
 * Problem: SCU4437 Carries
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
int n , a[maxn] , b[maxn];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
}

void work()
{
    lint ans = 0 , mod = 1;
    rep(k,1,10) {
        mod *= 10;
        rep(i,1,n) b[i] = a[i] % mod;
        sort( b + 1 , b + n + 1 );
        int p = n;
        rep(i,1,n) if ( b[i] + b[n] >= mod ) {
            while ( p > 1 && b[p-1] + b[i] >= mod ) p --;
            ans += n + 1 - p;
            if ( p <= i ) ans --;
        }
    }
    cout << ans / 2 << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
