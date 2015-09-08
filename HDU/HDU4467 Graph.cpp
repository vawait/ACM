/*
 * Author:  vawait
 * Created Time:  2015/9/5 13:13:01
 * Problem: HDU4467 Graph
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
#define ty( x , y ) ( (x) == (y) ? (x) : 2 )
typedef long long lint;
const int maxn = 101000;
int n , m , mx , size[maxn] , big[maxn] , color[maxn]; 
lint sum[maxn][2] , ans[4];
vector < pair < int , lint > > g[maxn];

struct nodd
{
    int x , y;
    lint w;
} a[maxn];

bool cmp(const nodd &a,const nodd &b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

void init()
{
    rep(i,0,3) ans[i] = 0;
    rep(i,1,n) {
        scanf("%d",color+i);
        size[i] = sum[i][0] = sum[i][1] = 0;
        g[i].clear();
    }
    rep(i,1,m) {
        scanf("%d%d%I64d",&a[i].x,&a[i].y,&a[i].w);
        size[a[i].x] ++;
        size[a[i].y] ++;
        if ( a[i].x < a[i].y ) swap( a[i].x , a[i].y );
    }
    sort( a + 1 , a + m + 1 , cmp );
    a[0].x = a[m+1].x = -1;
    red(i,m,1) if ( a[i].x == a[i+1].x && a[i].y == a[i+1].y ) a[i].w += a[i+1].w;
    mx = sqrt( m * 1.0 ) + 10;
    rep(i,1,n) big[i] = size[i] >= mx;
    int x , y;
    rep(i,1,m) if ( a[i].x != a[i-1].x || a[i].y != a[i-1].y ) {
        x = a[i].x , y = a[i].y;
        if ( size[x] > size[y] ) swap( x , y );
        ans[ty(color[x],color[y])] += a[i].w;
        if ( !big[x] && big[y] ) {
            g[x].pb( mp( y , a[i].w ) );
            sum[y][color[x]] += a[i].w;
        } else {
            g[x].pb( mp( y , a[i].w ) );
            g[y].pb( mp( x , a[i].w ) );
        }
    }
}

void work()
{
    int Q , x , y , col;
    char s[10];
    scanf("%d",&Q);
    while ( Q -- ) {
        scanf("%s",s);
        if ( s[0] == 'C' ) {
            scanf("%d",&x);
            col = color[x];
            red(i,g[x].size()-1,0) {
                y = g[x][i].x;
                ans[ty(col,color[y])] -= g[x][i].y;
                ans[ty(col^1,color[y])] += g[x][i].y;
            }
            if ( big[x] ) {
                rep(i,0,1) {
                    ans[ty(i,col)] -= sum[x][i];
                    ans[ty(i,col^1)] += sum[x][i];
                }
            } else {
                red(i,g[x].size()-1,0) if ( big[y=g[x][i].x] ) {
                    sum[y][col] -= g[x][i].y;
                    sum[y][col^1] += g[x][i].y;
                }
            }
            color[x] ^= 1;
        } else {
            scanf("%d%d",&x,&y);
            printf("%I64d\n",ans[ty(x,y)]);
        }
    }
}

int main()
{
    int t = 0;
    while ( cin >> n >> m ) {
        printf("Case %d:\n",++t);
        init();
        work();
    }
    return 0;
}
