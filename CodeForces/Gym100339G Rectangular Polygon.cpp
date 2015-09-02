/*
 * Author:  vawait
 * Created Time:  2015/9/2 13:46:59
 * Problem: Gym100339G Rectangular Polygon
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
int n , m , a[110] , f[110][21000] , pre[110][21000];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    
    clr( f , 240 );
    f[0][0] = 0;
    m = 200 * n;
}

void work()
{
    rep(i,0,n-1) 
        rep(j,0,m) if ( f[i][j] >= 0 ) {
            if ( f[i][j] > f[i+1][j] ) {
                f[i+1][j] = f[i][j];
                pre[i+1][j] = -1;
            }
            int x = a[i+1] , y = j + x;
            rep(k,0,1) {
                if ( k == 1 ) y = abs( j - x );
                if ( f[i][j] + 1 > f[i+1][y] ) {
                    f[i+1][y] = f[i][j] + 1;
                    pre[i+1][y] = j;
                }
            }
        }
    vector < int > g1 , g2;
    int sum1 = 0 , sum2 = 0 , p = 0 , ans = f[n][0];
    red(i,n,1) if ( pre[i][p] >= 0 ) {
        p = pre[i][p];
        if ( abs( sum1 + a[i] - sum2 ) == p ) {
            sum1 += a[i];
            g1.pb( a[i] );
        } else {
            sum2 += a[i];
            g2.pb( a[i] );
        }
    }
    cout << ans << endl;
    if ( ans ) {
        int sum = g1.size() - 1 , l = 0;
        rep(i,0,sum) {
            printf("%d %d\n",l,i+1);
            l += g1[i];
            printf("%d %d\n",l,i+1);
        }
        sum = g2.size() - 1;
        rep(i,0,sum) {
            printf("%d %d\n",l,-i);
            l -= g2[i];
            printf("%d %d\n",l,-i);
        }
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    init();
    work();
    return 0;
}
