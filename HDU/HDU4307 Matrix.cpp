/*
 * Author:  vawait
 * Created Time:  2015/7/31 19:10:07
 * Problem: HDU4307 Matrix
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
const int maxn = 1100;
int n , a[maxn] , vh[maxn] , h[maxn] , N = 1010 , S = 0 , t;
lint ans;

struct nodd
{
    int y , d , n;
} b[5001000];

void add(int x,int y,int d)
{
    b[++t].y = y; b[t].d = d;
    b[t].n = a[x]; a[x] = t;
    b[++t].y = x; b[t].d = 0;
    b[t].n = a[y]; a[y] = t;
}

int sap(int t,int d)
{
    int minh = 1010 , max = d , x , y;
    if ( t == N ) return d;
    for ( int p = a[t]; p; p = b[p].n ) if ( b[p].d > 0 ) {
        y = b[p].y;
        if ( h[y] + 1 == h[t] ) {
            x = sap( y , max > b[p].d ? b[p].d : max );
            b[p].d -= x; b[ p ^ 1 ].d += x;
            max -= x; 
            if ( !max || h[S] > 1010 ) return d - max;
        }
        if ( h[y] < minh ) minh = h[y];
    }
    if ( max == d ) {
        if ( !( -- vh[h[t]] ) ) h[S] = 1050;
        vh[ h[t] = minh + 1 ] ++;
    }
    return d - max;
}

void init()
{
    scanf("%d",&n);
    t = 1;
    clr( a , 0 );
    clr( h , 0 );
    clr( vh , 0 ); vh[0] = n + 2;
    ans = 0;
    rep(i,1,n) {
        int s = 0 , x;
        rep(j,1,n) {
            scanf("%d",&x);
            add( i , j , x );
            s += x;
        }
        add( S , i , s );
        ans += s;
    }
    int x;
    rep(i,1,n) scanf("%d",&x) , add( i , N , x );
}

void work()
{
    int mx = ( 1LL << 31 ) - 1;
    while ( h[S] <= n + 2 ) ans -= sap( S , mx );
    cout << ans << endl;
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
