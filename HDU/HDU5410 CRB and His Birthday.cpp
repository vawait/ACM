/*
 * Author:  vawait
 * Created Time:  2015/8/20 12:31:04
 * Problem: HDU5410 CRB and His Birthday
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
const int maxn = 2100;
int n , m , a[maxn] , b[maxn] , w[maxn] , f[maxn];

void init()
{
    scanf("%d%d",&m,&n);
    rep(i,1,n) scanf("%d%d%d",&w[i],&a[i],&b[i]);
    clr( f , 0 );
}

void work()
{
    rep(i,1,n) {
        int x = a[i] + b[i];
        red(j,m,w[i]) f[j] = max( f[j] , f[j-w[i]] + x );
    }
    rep(i,1,n) {
        rep(j,w[i],m) f[j] = max( f[j] , f[j-w[i]] + a[i] );
    }
    printf("%d\n",f[m]);
}

int main()
{
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
