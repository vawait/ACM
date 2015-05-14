/*
 * Author:  vawait
 * Created Time:  2015/5/14 23:23:32
 * Problem: BZOJ_2768
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
int a[410] , vh[410] , h[410] , N = 400 , S = 0 , t = 1;
int n , m , val[410];

struct nodd
{
    int y , d , n;
} b[100000];

void add(int x,int y,int d)
{
    b[++t].y = y; b[t].d = d;
    b[t].n = a[x]; a[x] = t;
    b[++t].y = x; b[t].d = d;
    b[t].n = a[y]; a[y] = t;
}

int sap(int t,int d)
{
    int minh = 400 , max = d , x , y;
    if ( t == N ) return d;
    for ( int p = a[t]; p; p = b[p].n ) if ( b[p].d ) {
        y = b[p].y;
        if ( h[y] + 1 == h[t] ) {
            x = sap( y , max > b[p].d ? b[p].d : max );
            b[p].d -= x; b[ p ^ 1 ].d += x;
            max -= x; 
            if ( !max || h[S] >= 400 ) return d - max;
        }
        if ( h[y] < minh ) minh = h[y];
    }
    if ( max == d ) {
        if ( !( -- vh[h[t]] ) ) h[S] = 400;
        vh[ h[t] = minh + 1 ] ++;
    }
    return d - max;
}

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    rep(i,1,n) {
        scanf("%d",&x);
        if ( x ) 
            add( 0 , i , 1 );
        else
            add( i , N , 1 );
    }
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        add( x , y , 1 );
    }
}

void work()
{
    int ans = 0;
    clr( h , 0 ); clr( vh , 0 );
    vh[0] = n + 2;
    while ( h[0] < 400 ) ans += sap( 0 , 10000 );
    cout << ans << endl;
    
}

int main()
{
    init();
    work();
    return 0;
}
