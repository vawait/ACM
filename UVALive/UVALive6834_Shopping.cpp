/*
 * Author:  vawait
 * Created Time:  2015/5/28 13:23:04
 * Problem: UVALive6834 Shopping
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
int n , m , sum , f[600];
pair < int , int > a[600];

void init()
{
    int x , y;
    sum = 0;
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        if ( y > x ) a[++sum] = mp( y , x );
    }
    if ( sum ) sort( a + 1 , a + sum + 1 );
    clr( f , 1 );
    f[0] = 0;
}

void work()
{
    rep(i,0,sum) {
        int mx = n + 1;
        rep(j,i+1,sum) {
            mx = min( mx , a[j].y );
            if ( mx > a[j].x ) mx = a[j].x;
            f[j] = min( f[j] , f[i] + abs( a[i].x - a[j].x ) + abs( a[j].x - mx ) * 2 );
        }
    }
    cout << f[sum] + n + 1 - a[sum].x << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
