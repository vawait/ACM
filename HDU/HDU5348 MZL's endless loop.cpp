/*
 * Author:  vawait
 * Created Time:  2015/8/4 13:17:32
 * Problem: HDU5348 MZL's endless loop
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long lint;
const int maxn = 301000;
int n , m , t , a[maxn] , a2[maxn] , ans[maxn] , in[maxn] , out[maxn];
int flag[maxn] , vis[maxn];

struct nodd
{
    int y , id , ty , n;
} b[maxn*20];

void add(int x,int y,int ty,int id)
{
    b[++t].y = y; b[t].ty = ty; b[t].id = id;
    b[t].n = a[x]; a[x] = t;
}

void init()
{
    t = 1;
    scanf("%d%d",&n,&m);
    rep(i,1,n) a[i] = in[i] = out[i] = 0 , flag[i] = 1;
    rep(i,1,m) ans[i] = -1;
    int x , y;
    rep(i,1,m) {
        ans[i] = -1;
        scanf("%d%d",&x,&y);
        if ( x != y ) {
            add( x , y , 1 , i );
            add( y , x , 0 , i );
        } else {
            ans[i] = 0;
        }
    }
    rep(i,1,n) a2[i] = a[i] , vis[i] = 0;
}

int dfs(int t,int fa)
{
    int y , p , f;
    vis[t] = 1;
    while ( a[t] ) {
        p = a[t]; y = b[p].y;
        a[t] = b[p].n;
        if ( ans[b[p].id] < 0 && ( b[p].id ^ fa ) ) {
            if ( vis[y] ) f = y; else f = dfs( y , b[p].id );
            if ( f ) {
                ans[b[p].id] = b[p].ty;
                if ( t != f ) {
                    vis[t] = 0;
                    return f;
                }
            }
        }
    }
    vis[t] = 0;
    flag[t] = 0;
    return 0;
}

void dfs2(int t)
{
    int p , y;
    while ( a[t] ) {
        p = a[t]; y = b[p].y;
        a[t] = b[p].n;
        if ( ans[b[p].id] < 0 ) {
            if ( in[t] >= out[t] ) {
                ans[b[p].id] = b[p].ty;
                out[t] ++; in[y] ++;
            } else {
                ans[b[p].id] = b[p].ty ^ 1;
                out[y] ++; in[t] ++;
            }
            dfs2( y );
        }
    }
}

void work()
{
    rep(i,1,n) if ( flag[i] ) dfs( i , 1 << 30 );
    rep(i,1,n) a[i] = a2[i];
    rep(i,1,n) if ( a[i] ) dfs2( i );
    rep(i,1,m) printf("%d\n",ans[i]);
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
