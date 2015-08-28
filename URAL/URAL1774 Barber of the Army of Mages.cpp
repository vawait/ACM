/*
 * Author:  vawait
 * Created Time:  2015/8/26 13:24:57
 * Problem: URAL1774 Barber of the Army of Mages
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
int n , a[4000] , vh[40000] , h[40000] , N = 3100 , S = 0 , t = 1;

struct nodd
{
    int y , d , n;
} b[1000000];

void add(int x,int y,int d)
{
    b[++t].y = y; b[t].d = d;
    b[t].n = a[x]; a[x] = t;
    b[++t].y = x; b[t].d = 0;
    b[t].n = a[y]; a[y] = t;
}

int sap(int t,int d)
{
    int minh = 3300 , max = d , x , y;
    if ( t == N ) return d;
    for ( int p = a[t]; p; p = b[p].n ) if ( b[p].d ) {
        y = b[p].y;
        if ( h[y] + 1 == h[t] ) {
            x = sap( y , max > b[p].d ? b[p].d : max );
            b[p].d -= x; b[ p ^ 1 ].d += x;
            max -= x; 
            if ( !max || h[S] > 3100 ) return d - max;
        }
        if ( h[y] < minh ) minh = h[y];
    }
    if ( max == d ) {
        if ( !( -- vh[h[t]] ) ) h[S] = 3300;
        vh[ h[t] = minh + 1 ] ++;
    }
    return d - max;
}

void init()
{
    int  l , r , k;
    vh[0] = 3100;
    scanf("%d%d",&n,&k);
    rep(i,1,n) {
        scanf("%d%d",&l,&r);
        r += l - 1;
        rep(j,l,r) add( i , 1000 + j , 1 );
        add( S , i , 2 );
    }
    rep(i,0,2000) add( i + 1000 , N , k );
}

void work()
{
    int ans = 0 , f[10];
    while ( h[S] <= 3100 ) ans += sap( S , n * 2 );
    if ( ans != 2 * n ) {
        puts("No");
        return;
    }
    puts("Yes");
    rep(i,1,n) {
        int sum = 0;
        for ( int p = a[i]; p ; p = b[p].n ) if ( b[p].y && !b[p].d ) {
            f[++sum] = b[p].y - 1000;
        }
        if ( f[1] > f[2] ) swap( f[1] , f[2] );
        printf("%d %d\n",f[1],f[2]);
    }
}

int main()
{
    init();
    work();
    return 0;
}
