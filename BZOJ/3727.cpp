/*
 * Author:  vawait
 * Created Time:  2014/10/17 13:47:53
 * File Name: BZOJ3727.cpp
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
const int maxn = 301000;
int n , ans[maxn] , b[maxn] , fa[maxn];
int q[maxn] , d[maxn];
lint s[maxn];
vector < int > a[maxn];

void bfs()
{
    int x , y , sum = 1;
    clr( d , 1 );
    d[1] = 0;
    q[1] = 1;
    rep(k,1,n) {
        x = q[k];
        red(i,a[x].size()-1,0) {
            y = a[x][i];
            if ( d[y] > d[x] + 1 ) {
                fa[y] = x;
                d[y] = d[x] + 1;
                q[++sum] = y;
            }
        }
    }
}

void init()
{
    int x , y;
    scanf("%d",&n);
    rep(i,1,n) a[i].clear();
    rep(i,1,n-1) {
        scanf("%d%d",&x,&y);
        a[x].pb( y );
        a[y].pb( x );
    }
    rep(i,1,n) scanf("%d",&b[i]);
    bfs();
}

void work()
{
    lint sum = 2 * b[1];
    int x , y;
    rep(i,2,n) sum += b[i] - b[fa[i]];
    s[1] = sum / ( n - 1 );
    rep(i,2,n) {
        x = q[i];
        s[x] = ( s[1] - b[x] + b[fa[x]] ) >> 1;
    }
    red(i,n,1) {
        x = q[i];
        sum = s[x];
        red(j,a[x].size()-1,0) if ( a[x][j] != fa[x] ) sum -= s[a[x][j]];
        ans[x] = sum;
    }
    rep(i,1,n-1) printf("%d ",ans[i]);
    printf("%d",ans[n]);
}

int main()
{
    init();
    work();
    return 0;
}
