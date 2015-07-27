/*
 * Author:  vawait
 * Created Time:  2015/7/27 13:37:43
 * Problem: HDU4283 You Are the One
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
int n , a[200] , sum[200] , g[200][200] , f[110][110];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    sum[0] = 0;
    rep(i,1,n) sum[i] = sum[i-1] + a[i];
    clr( f , 1 );
    rep(i,1,n) f[i][i] = f[i+1][i] = 0;
    rep(j,1,n) {
        g[j][j] = 0;
        red(i,j-1,1) g[i][j] = g[i+1][j] + ( j - i ) * a[i];
    }
}

void work()
{
    rep(len,1,n-1)
        rep(i,1,n-len) {
            int j = i + len;
            f[i][j] = f[i+1][j] + sum[j] - sum[i];
            rep(k,i,j-1) f[i][j] = min( f[i][j] , f[i][k] + ( k - i + 1 ) * ( sum[j] - sum[k] ) + f[k+1][j] );
            rep(k,i,j-1) f[i][j] = min( f[i][j] , g[i][k] + ( j - k ) * ( sum[k] - sum[i-1] ) + f[k+1][j] ); 
        }
    printf("%d\n",f[1][n]);
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
