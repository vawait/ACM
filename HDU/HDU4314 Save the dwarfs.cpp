/*
 * Author:  vawait
 * Created Time:  2015/7/31 20:35:15
 * Problem: HDU4314 Save the dwarfs
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
int n , h , f[2010] , sum[2010];
pair < int , int > a[2010];

void init()
{
    rep(i,1,n) scanf("%d%d",&a[i].y,&a[i].x) , a[i].x += a[i].y;
    scanf("%d",&h);
    sort( a + 1 , a + n + 1 );
    clr( f , 250 );
    f[0] = 0;
    sum[n+1] = 0;
    red(i,n,1) sum[i] = sum[i+1] + a[i].y;
}

void work()
{
    rep(i,0,n-1) 
        red(j,i,0) {
            if ( f[j] + a[i+1].x + sum[i+2] >= h ) 
                f[j+1] = max( f[j+1] , f[j] );
            f[j] += a[i+1].y;
        }
    int ans = 0;
    rep(i,0,n) if ( f[i] >= 0 ) ans = max( ans , i );
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
