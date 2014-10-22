/*
 * Author:  vawait
 * Created Time:  2014/10/1 20:52:08
 * File Name: BZOJ3712.cpp
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
const int maxn = 401000;
int n , m , k , g[maxn] , d[maxn] , dfn[maxn];
int s , f[maxn] , f1[maxn] , f2[maxn] , v[maxn];
vector < int > a[maxn];
pair < int , int > q[maxn*2] , Q[maxn*2];
vector < pair < int , int > > b[maxn];

int find(int *f,int t)
{
    return f[t] == t ? t : ( f[t] = find( f , f[t] ) );
}

void init()
{
    int t , x , y , p , q;
    scanf("%d%d%d",&n,&m,&k);
    t = n;
    rep(i,1,n+m) f2[i] = f1[i] = f[i] = i;
    rep(i,1,n) scanf("%d",&g[i]);
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        f[find(f,x)] = find( f , y );
        p = find( f1 , x );
        q = find( f1 , y );
        f1[p] = f1[q] = ++n;
        d[p] = d[q] = 1;
        a[n].pb( p );
        a[n].pb( q );
    }
    rep(i,1,k) {
        scanf("%d%d",&x,&y);
        Q[i] = mp( x , y );
        b[x].pb( mp( y , i ) );
        b[y].pb( mp( x , i ) );
    }
}

void dfs(int t)
{
    int y , x;
    v[t] = 1;
    red(i,a[t].size()-1,0) {
        y = a[t][i];
        dfn[y] = dfn[t] - 1;
        dfs( y );
        f2[find(f2,y)] = t;
    }
    red(i,b[t].size()-1,0) {
        y = b[t][i].x;
        if ( v[y] && find( f , y ) == find( f , t ) )
            q[++s] = mp( dfn[find( f2 , y )] , b[t][i].y );
    }
}

void work()
{
    int x , l , r;
    lint ans = 0;
    rep(i,1,n) if ( !d[i] ) dfs( i );
    if ( s ) sort( q + 1 , q + 1 + s );
    rep(i,1,s) {
        x = q[i].y ; l = Q[x].x ; r = Q[x].y;
        x = min( g[l] , g[r] );
        ans += x * 2;
        g[l] -= x;
        g[r] -= x;
    }
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
