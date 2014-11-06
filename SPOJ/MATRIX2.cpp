/*
 * Author:  vawait
 * Created Time:  2014/11/6 15:16:40
 * Problem: SPOJ_MATRIX2
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
int a[1010][1010] , b[1010][1010] , s[1010][1010] , h[1010][1010];
int n , m , A , B , C , D , xx , yy;
pair < int , int > q[1010];

void init()
{
    scanf("%d%d%d%d%d%d",&n,&m,&A,&B,&C,&D);
    rep(i,1,n) {
        scanf("%d",&a[i][1]);
        rep(j,2,m) a[i][j] = ( a[i][j-1] * 71 + 17 ) % 100 + 1;
    }
    rep(i,1,n)
        rep(j,1,m) s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    rep(i,1,n) if ( i + C - 1 <= n )
        rep(j,1,m) if ( j + D - 1 <= m )
            b[i][j] = s[i+C-1][j+D-1] - s[i-1][j+D-1] - s[i+C-1][j-1] + s[i-1][j-1];
    xx = A - 1 - C;
    yy = B - 1 - D;
}

void deal() 
{
    int l , r;
    rep(i,1,n) {
        l = 1; r = 0;
        red(j,m,1) {
            while ( l <= r && q[r].x >= b[i][j] ) r --;
            q[++r] = mp( b[i][j] , j );
            while ( l <= r && q[l].y >= j + yy ) l ++;
            h[i][j] = q[l].x;
        } 
    }
    rep(j,1,m) {
        l = 1; r = 0;
        red(i,n,1) {
            while ( l <= r && q[r].x >= h[i][j] ) r --;
            q[++r] = mp( h[i][j] , i );
            while ( l <= r && q[l].y >= i + xx ) l ++;
            a[i][j] = q[l].x;
        }
    }
}

void work()
{
    int ans = -1e9 , sum = 0;
    if ( C && D ) deal();
    rep(i,A,n)
        rep(j,B,m) {
            sum = s[i][j] - s[i-A][j] - s[i][j-B] + s[i-A][j-B];
            if ( C && D ) ans = max( ans , sum - a[i-A+2][j-B+2] );
            else ans = max( ans , sum );
        }
    printf("%d\n",ans);
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
