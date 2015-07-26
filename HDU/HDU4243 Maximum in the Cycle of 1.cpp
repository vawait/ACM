/*
 * Author:  vawait
 * Created Time:  2015/7/26 15:23:07
 * Problem: HDU4243 Maximum in the Cycle of 1
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
typedef unsigned long long lint;
lint f[40] , n , k;

lint C(int n,int m)
{
    return f[n] / f[m] / f[n-m];
}

void init()
{
    f[0] = 1;
    rep(i,1,20) f[i] = f[i-1] * i;
}

void work()
{
    lint ans = 0;
    cin >> n >> k;
    if ( k == 1 ) {
        ans = f[n-1];
    } else {
        rep(i,0,k-2) ans += C( k - 2 , i ) * f[i+1] * f[n-2-i]; 
    }
    cout << ans << endl;
}

int main()
{
    int N , t;
    for ( cin >> t; t; t--) {
        cin >> N;
        printf("%d ",N);
        init();
        work();
    }
    return 0;
}
