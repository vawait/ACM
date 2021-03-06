/*
 * Author:  vawait
 * Created Time:  2014/10/28 17:13:14
 * File Name: CodeChefSKIRES.cpp
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
#define num( x , y ) ( ( x - 1 ) * m + y )
typedef long long lint;
int n , m , sx , sy , tx , ty , d[60][60];
int a[13000] , vh[13000] , h[13000] , N , S , t;
int dx[] = { 0 , 0 , -1 , 1 };
int dy[] = { 1 , -1 , 0 , 0 };

struct nodd
{
    int y , d , n;
} b[400000];

void add(int x,int y,int d)
{
    b[++t].y = y; b[t].d = d;
    b[t].n = a[x]; a[x] = t;
    b[++t].y = x; b[t].d = 0;
    b[t].n = a[y]; a[y] = t;
}

int sap(int t,int d)
{
    int minh = 12600 , max = d , x , y;
    if ( t == N ) return d;
    for ( int p = a[t]; p; p = b[p].n ) if ( b[p].d ) {
        y = b[p].y;
        if ( h[y] + 1 == h[t] ) {
            x = sap( y , max > b[p].d ? b[p].d : max );
            b[p].d -= x; b[ p ^ 1 ].d += x;
            max -= x; 
            if ( !max || h[S] > 12600 ) return d - max;
        }
        if ( h[y] < minh ) minh = h[y];
    }
    if ( max == d ) {
        if ( !( -- vh[h[t]] ) ) h[S] = 12700;
        vh[ h[t] = minh + 1 ] ++;
    }
    return d - max;
}

bool ok(int x,int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void init()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    S = num( sx , sy ); N = num( tx , ty );
    t = 1;
    clr( a , 0 );
    rep(i,1,n)
        rep(j,1,m) scanf("%d",&d[i][j]);
    
    int s = n * m;
    rep(i,1,n)
        rep(j,1,m) {
            vector < pair < int , int > > q;
            rep(k,0,3) {
                int x = i + dx[k] , y = j + dy[k];
                if ( ok( x , y ) && d[i][j] <= d[x][y] )
                    q.pb( mp( num( i , j ) == N ? 10000000 : d[x][y] - d[i][j] + 1 , num( x , y ) ) );
            }
            sort( q.begin() , q.end() );
            int l = q.size() - 1;
            rep(r,0,l) add( q[r].y , ++s , 100000000 ) , q[r].y = s;
            rep(r,0,l-1) add( q[r].y , q[r+1].y , q[r].x );
            if ( !q.empty() ) add( q[l].y , num( i , j ) , q[l].x );
        }
                
    clr( h , 0 ); clr( vh , 0 );
    vh[0] = 130000;
}

void work()
{
    int ans = 0;
    while ( h[S] <= 12600 ) ans += sap( S , 100000000 );
    if ( ans > 1260000 ) ans = -1;
    printf("%d\n",ans);
}

int main()
{
    int t;
    for ( cin >> t; t; t -- ) {
        init();
        work();
    }
    return 0;
}
