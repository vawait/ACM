/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月02日 星期日 12时58分00秒
 * File Name: HDU4034.cpp
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
int n , a[110][110];

void init()
{
    scanf("%d",&n);
    rep(i,1,n)
        rep(j,1,n) scanf("%d",&a[i][j]);
}

void work()
{
    int ans = 0 , v;
    rep(i,1,n)
        rep(j,1,n) if ( i != j ) {
            v = 1;
            rep(k,1,n) if ( k != i && k != j ) {
                if ( a[i][k] + a[k][j] < a[i][j] ) {
                    puts("impossible");
                    return;
                }
                if ( a[i][k] + a[k][j] == a[i][j] ) v = 0;
            }
            ans += v;
        }
    printf("%d\n",ans);
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case %d: ",i);
        init();
        work();
    }
    return 0;
}
