/*
 * Author:  vawait
 * Created Time:  2015/8/28 17:09:43
 * Problem: BZOJ2132 圈地计划
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
const int maxm = 11000;
int a[maxm] , vh[maxm] , h[maxm] , N = 10100 , S = 0 , t = 1;
int n , m , ans = 0 , A[110][110] , B[110][110] , C[110][110];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };

struct nodd
{
    int y , d , n;
} b[300000];

void add(int x,int y,int d)
{
    b[++t].y = y; b[t].d = d;
    b[t].n = a[x]; a[x] = t;
    b[++t].y = x; b[t].d = 0;
    b[t].n = a[y]; a[y] = t;
}

int sap(int t,int d)
{
    int minh = N + 10 , max = d , x , y;
    if ( t == N ) return d;
    for ( int p = a[t]; p; p = b[p].n ) if ( b[p].d ) {
        y = b[p].y;
        if ( h[y] + 1 == h[t] ) {
            x = sap( y , max > b[p].d ? b[p].d : max );
            b[p].d -= x; b[ p ^ 1 ].d += x;
            max -= x; 
            if ( !max || h[S] >= N ) return d - max;
        }
        if ( h[y] < minh ) minh = h[y];
    }
    if ( max == d ) {
        if ( !( -- vh[h[t]] ) ) h[S] = N + 10;
        vh[ h[t] = minh + 1 ] ++;
    }
    return d - max;
}

int num(int x,int y)
{
    return ( x - 1 ) * m + y;
}

void init()
{
    scanf("%d%d",&n,&m);
    vh[0] = n * m + 10;
    rep(i,1,n) 
        rep(j,1,m) scanf("%d",&A[i][j]) , ans += A[i][j];
    rep(i,1,n) 
        rep(j,1,m) scanf("%d",&B[i][j]) , ans += B[i][j];
    rep(i,1,n) 
        rep(j,1,m) scanf("%d",&C[i][j]);
    rep(i,1,n)
        rep(j,1,m) if ( ( i + j ) & 1 ) {
            add( 0 , num( i , j ) , A[i][j] );
            add( num( i , j ) , N , B[i][j] );
        } else {
            add( 0 , num( i , j ) , B[i][j] );
            add( num( i , j ) , N , A[i][j] );
        }
    rep(i,1,n)
        rep(j,1,m)
            rep(k,0,3) {
                int x = i + dx[k] , y = j + dy[k];
                if ( x > n || x < 1 || y > m || y < 1 ) continue;
                add( num( i , j ) , num( x , y ) , C[i][j] + C[x][y] );
                ans += C[i][j];
            }
}

void work()
{
    while ( h[S] <= N ) ans -= sap( S , 1e8 );
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
