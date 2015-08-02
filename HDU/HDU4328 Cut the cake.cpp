/*
 * Author:  vawait
 * Created Time:  2015/8/2 21:43:51
 * Problem: HDU4328 Cut the cake
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
const int maxn = 1010;
int n , m , ans , a[maxn][maxn];
int h[maxn][maxn] , l[maxn][maxn] , r[maxn][maxn];
char c[maxn];

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) {
        scanf("%s",c+1);
        rep(j,1,m) a[i][j] = ( c[j] == 'R' );
    }
    ans = 0;
}

void calc(int t)
{
    rep(i,1,m) r[0][i] = m;
    rep(i,1,n) {
        int L = 0 , R = m + 1;
        rep(j,1,m) if ( a[i][j] == t ) {
            h[i][j] = l[i][j] = 0;
            L = j;
        } else {
            h[i][j] = h[i-1][j] + 1;
            l[i][j] = max( l[i-1][j] , L + 1 );
        }
        red(j,m,1) if ( a[i][j] == t ) {
            r[i][j] = m;
            R = j;
        } else {
            r[i][j] = min( r[i-1][j] , R - 1 );
            ans = max( ans , ( h[i][j] + r[i][j] - l[i][j] + 1 ) * 2 ); 
        }
    }
}

void work()
{
    calc( 1 );
    calc( 0 );
    rep(i,1,n)
        rep(j,1,m) if ( ( i + j ) & 1 ) a[i][j] ^= 1;
    calc( 1 );
    calc( 0 );
    printf("%d\n",ans);
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
