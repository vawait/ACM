/*
 * Author:  vawait
 * Created Time:  2015/1/24 0:54:02
 * Problem: CodeForces_507E
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
const int maxn = 101000;
int n , m , va[maxn] , vb[maxn] , vz[maxn] , d[maxn] , f[maxn];
int v[maxn] , use[maxn] , p[maxn] , px[maxn];
vector < pair < int , int > > a[maxn];

void bfs()
{
    queue < int > q;
    int x , y;
    q.push( 1 );
    clr( d , 1 ); clr( v , 0 );
    v[1] = 1; d[1] = 0;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        v[x] = 0;
        red(i,a[x].size()-1,0) {
            y = a[x][i].x;
            if ( d[x] + 1 < d[y] ) {
                d[y] = d[x] + 1;
                p[y] = x;
                if ( !v[y] ) v[y] = 1 , q.push( y );
            }
        }
    }
}

void bfs2()
{
    queue < int > q;
    int x , y , z;
    q.push( 1 );
    clr( f , 244 ); clr( v , 0 );
    v[1] = 1; f[1] = 0;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        v[x] = 0;
        red(i,a[x].size()-1,0) {
            y = a[x][i].x;
            z = vz[a[x][i].y];
            if ( d[x] + 1 == d[y] && f[x] + ( z == 1 ) >= f[y] ) {
                f[y] = f[x] + ( z == 1 );
                p[y] = a[x][i].y;
                px[y] = x;
                if ( !v[y] ) v[y] = 1 , q.push( y );
            }
        }
    }
    
    clr( use , 0 );
    for ( x = n; x != 1; x = px[x] ) {
        use[p[x]] = 1;
    }
}

void init()
{
    rep(i,1,n) a[i].clear();
    rep(i,1,m) {
        scanf("%d%d%d",&va[i],&vb[i],&vz[i]);
        a[va[i]].pb( mp( vb[i] , i ) );
        a[vb[i]].pb( mp( va[i] , i ) );
    }
    bfs();
}

void work()
{
    int sum = 0 , x;
    bfs2();
    rep(i,1,m) {
        if ( !use[i] && vz[i] ) {
            p[++sum] = i;
            d[sum] = 0;
        }
        if ( use[i] && !vz[i] ) {
            p[++sum] = i;
            d[sum] = 1;
        }
    }
    printf("%d\n",sum);
    rep(i,1,sum) {
        x = p[i];
        printf("%d %d %d\n",va[x],vb[x],d[i]);
    }
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
