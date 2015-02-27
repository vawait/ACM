/*
 * Author:  vawait
 * Created Time:  2015/2/23 13:06:54
 * Problem: test.cpp
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
int n , v , s[300000];

void init()
{
    int a , b;
    clr( s , 0 );
    rep(i,1,n) scanf("%d%d",&a,&b) , s[a] += b;
}

void work()
{
    int ans = 0 , vv;
    rep(i,1,3100) {
        ans += min( s[i-1] , v );
        vv = v - min( s[i-1] , v );
        ans += min( s[i] , vv );
        s[i] -= min( s[i] , vv );
    }
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n >> v ) {
        init();
        work();
    }
    return 0;
}
