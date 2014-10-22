/*
 * Author:  vawait
 * Created Time:  2014/10/21 12:34:58
 * File Name: BZOJ1040.cpp
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
const int maxn = 1001000;
int n , ax , ay , at , v[maxn] , fa[maxn] , b[maxn];
int s , q[maxn];
vector < int > a[maxn];
lint f[maxn][2];

void init()
{
    int x;
    scanf("%d",&n);
    rep(i,1,n) a[i].clear();
    rep(i,1,n) {
        scanf("%d%d",&b[i],&x);
        a[x].pb( i );
        a[i].pb( x );
    }
    clr( v , 0 );
}

void bfs(int t)
{
    int x , y , p = 1;
    q[s=1] = t;
    fa[t] = 0;
    v[t] = 1;
    while ( p <= s ) {
        x = q[p++];
        red(i,a[x].size()-1,0) {
            y = a[x][i];
            if ( v[y] && y != fa[x] && fa[y] != x ) ax = x , ay = y;
            if ( !v[y] ) q[++s] = y , v[y] = -1 , fa[y] = x;
        }
    }
}

lint fbfs()
{
    int x , y;
    red(i,s,1) v[q[i]] = -1;
    red(i,s,1) {
        x = q[i];
        f[x][1] = b[x];
        f[x][0] = 0;
        red(j,a[x].size()-1,0) {
            y = a[x][j];
            if ( fa[y] == x && v[y] != x ) {
                v[y] = x;
                f[x][1] += f[y][0];
                f[x][0] += max( f[y][0] , f[y][1] );
            }
        }
        if ( x == at ) f[x][1] = -10000000000000LL;
    }
    return max( f[x][1] , f[x][0] );
}

void work()
{
    lint ans = 0 , x;
    rep(i,1,n) if ( !v[i] ) {
        ax = ay = 0;
        fa[i] = 0;
        bfs( i );
        at = ax;
        x = fbfs();
        at = ay;
        ans += max( x , fbfs() );
    }
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
