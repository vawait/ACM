/*
 * Author:  vawait
 * Created Time:  2015/5/15 17:27:34
 * Problem: BZOJ_1018
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
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
const int maxn = 101000;
int n , Right[maxn][2] , Down[maxn];
int al , x1 , y1 , x2 , y2;
char c[100];

struct nodd
{
    bool a[2][2];
} a[maxn*10];

struct zkw
{
    static const int mm = 1 << 17;
	int a[2][1<<19];
	void cha(int x,int k) {
		x += mm;
        a[0][x] = a[1][x] = k;
        if ( !k ) a[0][x] = n + 1;
        for ( x >>= 1; x; x >>= 1 ) {
            a[0][x] = min( a[0][x<<1] , a[0][x<<1|1] );
            a[1][x] = max( a[1][x<<1] , a[1][x<<1|1] );
        }
	}
	int ask(int l,int r,int k) {
		int ans = k ? 0 : n + 1;
		l += mm - 1; r += mm + 1;
		for ( ; l^r^1; l>>=1 , r>>=1 ) {
			if ( ~l&1 ) {
                ans = k ? max( ans , a[1][l^1] ) : min( ans , a[0][l^1] );
            }
            if ( r & 1 ) {
                ans = k ? max( ans , a[1][r^1] ) : min( ans , a[0][r^1] );
            }
		}
		return ans;
	}
} T;

void init()
{
    scanf("%d",&n);
    clr( T.a[0] , 1 );
}

nodd calc(nodd b,nodd c,int mid)
{
    nodd a;
    clr( a.a , 0 );
    rep(i,0,1) rep(j,0,1) 
        rep(k,0,1) if ( Right[mid][k] && b.a[i][k] && c.a[k][j] )
            a.a[i][j] = 1;
    return a;
}

void cha(int t,int l,int r)
{
    if ( l == r ) {
        a[t].a[0][0] = a[t].a[1][1] = 1;
        a[t].a[0][1] = a[t].a[1][0] = Down[l];
        return;
    }
    int mid = ( l + r ) >> 1;
    if ( mid >= al )
        cha( t << 1 , l , mid );
    else 
        cha( t << 1 | 1 , mid + 1 , r );
    a[t] = calc( a[t<<1] , a[t<<1|1] , mid );
}

nodd ask(int t,int l,int r)
{
    if ( l >= y1 && r <= y2 ) return a[t];
    int mid = ( l + r ) >> 1;
    if ( y2 <= mid ) return ask( t << 1 , l , mid );
    if ( y1 > mid ) return ask( t << 1 | 1 , mid + 1 , r );
    return calc( ask( t << 1 , l , mid ) , ask( t << 1 | 1 , mid + 1 , r ) , mid );
}

void work()
{
    while ( 1 ) {
        scanf("%s",c);
        if ( c[0] == 'E' ) return;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1 --; x2 --;
        if ( c[0] == 'O' || c[0] == 'C' ) {
            if ( y1 == y2 ) {
                if ( x1 != x2 ) Down[y1] = c[0] == 'O';
            } else {
                if ( abs( y1 - y2 ) == 1 && x1 == x2 ) Right[min(y1,y2)][x1] = c[0] == 'O';
            }
            al = y1;
            cha( 1 , 1 , n );
            al = y2;
            cha( 1 , 1 , n );
            if ( y1 == y2 ) T.cha( y1 , Down[y1] ? y1 : 0 );
        } else {
            if ( y1 > y2 ) swap( y1 , y2 ) , swap( x1 , x2 );
            nodd ans = ask( 1 , 1 , n );
            int yy1 = y1 , yy2 = y2;
            y1 = T.ask( 1 , yy1 , 1 );
            y2 = yy1;
            if ( y1 >= 1 && y1 < y2 ) {
                nodd ans2 = ask( 1 , 1 , n );
                if ( ans2.a[0][1] && ans2.a[1][0] ) ans = calc( ans2 , ans , yy1 - 1 );
            }
            y1 = yy2;
            y2 = T.ask( yy2 , n , 0 );
            if ( y2 <= n && y2 > y1 ) {
                nodd ans2 = ask( 1 , 1 , n );
                if ( ans2.a[0][1] && ans2.a[1][0] ) ans = calc( ans , ans2 , yy2 );
            }
            puts( ans.a[x1][x2] ? "Y" : "N" );
        }
    }
}

int main()
{
    init();
    work();
    return 0;
}
