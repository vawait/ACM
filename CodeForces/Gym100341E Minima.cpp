/*
 * Author:  vawait
 * Created Time:  2015/8/31 15:00:48
 * Problem: Gym100341E Minima
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
int n , a , b;

void init()
{
    scanf("%d%d%d",&n,&a,&b);
}

void work()
{
    int ans = -1 , x = 0 , y = 0;
    rep(i,1,n) {
        int mx = min( n , i + 2000 );
        rep(j,i,mx) if ( ( i & j ) == i )
            if ( ( ( a * i + b * j ) ^ ( a * j + b * i ) ) >= ans )
                ans = ( a * i + b * j ) ^ ( a * j + b * i ) , x = i , y = j;
        mx = max( i , n - 2000 );
        rep(j,mx,n) if ( ( i & j ) == i )
            if ( ( ( a * i + b * j ) ^ ( a * j + b * i ) ) >= ans )
                ans = ( a * i + b * j ) ^ ( a * j + b * i ) , x = i , y = j;
    }
    printf("%d %d\n",y,x);
}

int main()
{
    freopen("crypto.in","r",stdin);
    freopen("crypto.out","w",stdout);
    init();
    work();
    return 0;
}
