/*
 * Author:  vawait
 * Created Time:  2015/7/27 16:11:47
 * Problem: HDU4293 Groups
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
int n , f[600] , sum[600][600];
pair < int , int > a[600];

void init()
{
    int x , y;
    clr( sum , 0 );
    rep(i,1,n) {
        scanf("%d%d",&x,&y);
        if ( x + y < n ) sum[n-y][x] ++;
    }
    clr( f , 0 );
}

void work()
{
    int ans = 0;
    rep(i,1,n) 
        rep(j,0,i-1) f[i] = max( f[i] , f[j] + min( i - j , sum[i][j] ) );
    rep(i,1,n) ans = max( ans , f[i] );
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
