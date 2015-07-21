/*
 * Author:  vawait
 * Created Time:  2015/7/21 12:52:05
 * Problem: HDU5294 Tricks Device
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
const int maxn = 3000;
int n , m , vis[maxn];
vector < pair < int , int > > g[maxn];
pair < int , int > d[maxn];

int a[maxn] , vh[maxn] , h[maxn] , N , S = 0 , t;

struct nodd
{
    int y , d , n;
} b[200000];

void add(int x,int y,int d)
{
    b[++t].y = y; b[t].d = d;
    b[t].n = a[x]; a[x] = t;
    b[++t].y = x; b[t].d = 0;
    b[t].n = a[y]; a[y] = t;
}

int sap(int t,int d)
{
    int minh = 2055 , max = d , x , y;
    if ( t == N ) return d;
    for ( int p = a[t]; p; p = b[p].n ) if ( b[p].d ) {
        y = b[p].y;
        if ( h[y] + 1 == h[t] ) {
            x = sap( y , max > b[p].d ? b[p].d : max );
            b[p].d -= x; b[ p ^ 1 ].d += x;
            max -= x; 
            if ( !max || h[S] > 2050 ) return d - max;
        }
        if ( h[y] < minh ) minh = h[y];
    }
    if ( max == d ) {
        if ( !( -- vh[h[t]] ) ) h[S] = 2100;
        vh[ h[t] = minh + 1 ] ++;
    }
    return d - max;
}

void spfa()
{
    int x , y;
    pair < int , int > pp;
    queue < int > q;
    q.push( 1 );
    d[1] = mp( 0 , 0 );
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        vis[x] = 0;
        red(i,g[x].size()-1,0) {
            y = g[x][i].x;
            pp = mp( d[x].x + g[x][i].y , d[x].y + 1 );
            if ( pp < d[y] ) {
                d[y] = pp;
                if ( !vis[y] ) vis[y] = 1 , q.push( y );
            }
        }
    }
}

void init()
{
    int x , y , dd;
    rep(i,1,n) vis[i] = 0 , g[i].clear() , d[i] = mp( 1e9 , 1e9 );
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&dd);
        g[x].pb( mp( y , dd ) );
        g[y].pb( mp( x , dd ) );
    }
    spfa();
}

void work()
{
    int ans = 0;
    clr( vh , 0 ); vh[0] = n;
    clr( h , 0 );
    clr( a , 0 );
    t = 1; N = n; S = 1;
    rep(i,1,n) 
        red(j,g[i].size()-1,0) if ( d[i].x + g[i][j].y == d[g[i][j].x].x )
            add( i , g[i][j].x , 1 );
    while ( h[S] <= 2010 ) ans += sap( S , 100000 );
    printf("%d %d\n",ans,m-d[n].y);
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
