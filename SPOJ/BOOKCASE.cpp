/*
 * Author:  vawait
 * Created Time:  2014/11/2 21:12:39
 * Problem: SPOJ_BOOKCASE
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
#define h first
#define w second
#define sqr(x) ((x) * (x))
typedef long long lint;
int n , f[2100][2100];
pair < int , int > a[80];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&a[i].h,&a[i].w);
    sort( a + 1 , a + n + 1 );
    clr( f , 1 );
    f[0][0] = 0;
}

void mx(int &x,int y)
{
    if ( x > y ) x = y;
}

void work()
{
    int sum = 0 , w , h , ans = 1e9;
    red(k,n-1,1) {
        w = a[k].w , h = a[k].h;
        red(i,sum,0)
            red(j,sum-i,0) if ( f[i][j] < 10000 ) {
                mx( f[i+w][j] , f[i][j] + ( i ? 0 : h ) );
                mx( f[i][j+w] , f[i][j] + ( j ? 0 : h ) );
            }
        sum += a[k].w;
    }
    red(i,sum,1)
        red(j,sum-i,1) if ( f[i][j] < 10000 )
            mx( ans , ( f[i][j] + a[n].h ) * max( max( i  , j ) , ( sum - i - j + a[n].w ) ) );
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
