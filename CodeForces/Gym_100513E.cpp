/*
 * Author:  vawait
 * Created Time:  2015/5/21 14:38:54
 * Problem: Gym_100513E
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
const int maxn = 201000;
int n , sum , mx , a[maxn] , b[maxn] , q[maxn];

void init()
{
    int last = 0;
    sum = mx = 0;
    rep(i,1,n) scanf("%d%d",&a[i],&b[i]);
    rep(i,1,n) if ( a[i] > b[i] ) mx ++;
    rep(i,1,n) if ( i - last > 1 ) {
        int x = ( a[i] > b[i] ) + ( a[i-1] > b[i-1] );
        int y = ( a[i] + a[i-1] > b[i] + b[i-1] );
        if ( y == x )
            q[++sum] = i , last = i;
    }
}

void work()
{
    rep(i,0,sum) if ( ( n - i ) / 2 < mx ) {
        printf("%d\n",i);
        rep(j,1,i) printf("%d %d\n",q[j]-1,q[j]);
        return;
    }
    puts("-1");
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
