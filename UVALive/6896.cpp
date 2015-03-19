/*
 * Author:  Twist Of Fate
 * Created Time:  2015年03月19日 星期四 12时34分04秒
 * File Name: UVALive_6896
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
typedef long long lint;
int s , a[2100] , b[4100];

void init()
{
    s = 0;
    rep(i,1,100) {
        int x = i * ( i + 1 ) / 2;
        if ( x > 1000 ) break;
        a[++s] = x;
    }
    rep(i,1,s)
        rep(j,1,s)
            rep(k,1,s) b[a[i]+a[j]+a[k]] = 1;
}

void work()
{
    int t , n;
    cin >> t;
    while ( t -- ) scanf("%d",&n) , printf("%d\n",b[n]);
}

int main()
{
    init();
    work();
    return 0;
}
