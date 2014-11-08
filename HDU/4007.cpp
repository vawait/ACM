/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月08日 星期六 13时22分43秒
 * File Name: HDU_4007
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define db pop_back
#define x first
#define y second
typedef long long lint;
int n , r , s , q[1100];
pair < int , int > a[1100];

void init()
{
    rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    sort( a + 1 , a + 1 + n );
}

void work()
{
    int ans = 0 , x;
    rep(k,1,n) {
        s = 0;
        x = 1;
        rep(i,1,n) if ( a[i].y <= a[k].y + r && a[i].y >= a[k].y )
            q[++s] = a[i].x;
        rep(i,1,s) {
            while ( x <= i && q[x] + r < q[i] ) x ++;
            ans = max( ans , i - x + 1 ); 
        }
    }
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n >> r ) {
        init();
        work();
    }
    return 0;
}
