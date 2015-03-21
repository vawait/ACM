/*
 * Author:  vawait
 * Created Time:  2015/3/18 19:14:05
 * Problem: CodeForces_528C
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
int n , m , sum , f[maxn] , q[maxn] , ans[maxn*2];
multiset < int > g[maxn];
multiset < int > :: iterator it;

void init()
{
    int x , y;
    rep(i,1,n) f[i] = 0 , g[i].clear();
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        f[x] ++; f[y] ++;
        g[x].insert( y );
        g[y].insert( x );
    }
    sum = 0;
    rep(i,1,n) if ( f[i] & 1 ) q[++sum] = i;
    for ( int i = 1; i <= sum; i += 2 ) {
        m ++;
        g[q[i]].insert( q[i+1] );
        g[q[i+1]].insert( q[i] );
    }
    if ( m & 1 ) m ++ , g[1].insert( 1 ) , g[1].insert( 1 );
    sum = 0;
}

void dfs(int t)
{
    int y;
    while ( !g[t].empty() ) {
        y = *g[t].begin();
        g[t].erase( g[t].begin() );
        g[y].erase( g[y].find( t ) );
        dfs( y );
    }
    ans[++sum] = t;
}

void work()
{
    dfs( 1 );
    printf("%d\n",m);
    rep(i,1,sum-1) if ( i & 1 ) {
        printf("%d %d\n",ans[i],ans[i+1]);
    } else {
        printf("%d %d\n",ans[i+1],ans[i]);
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
