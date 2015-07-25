/*
 * Author:  vawait
 * Created Time:  2015/7/25 13:08:10
 * Problem: HDU4161 Iterated Difference
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
int n , now = 0 , nex = 1 , a[2][40];

void init()
{
    rep(i,1,n) scanf("%d",&a[now][i]);
}

void work()
{
    rep(ans,0,1000) {
        int v = 1;
        rep(i,2,n) if ( a[now][i] != a[now][i-1] ) v = 0;
        if ( v ) {
            printf("%d iterations\n",ans);
            return;
        }
        swap( now , nex );
        rep(i,1,n-1) a[now][i] = abs( a[nex][i] - a[nex][i+1] );
        a[now][n] = abs( a[nex][n] - a[nex][1] );
    }
    puts("not attained");
}

int main()
{
    int t = 0;
    while ( scanf("%d",&n) && n ) {
        printf("Case %d: ",++t);
        init();
        work();
    }
    return 0;
}
