/*
 * Author:  vawait
 * Created Time:  2015/8/1 13:45:26
 * Problem: HDU4337 King Arthur's Knights
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
int n , m , a[160][160] , d[160] , vis[160];
int q[160];

void init()
{
    int x , y;
    clr( a , 0 );
    clr( d , 0 );
    clr( vis , 0 );
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        a[x][y] = a[y][x] = 1;
        d[x] ++ ; d[y] ++;
    }
}

bool dfs(int t,int s)
{
    q[s] = t;
    if ( s == n ) {
        return a[t][1];
    }
    vis[t] = 1;
    rep(i,1,n) if ( a[t][i] && !vis[i] && dfs( i , s + 1 ) ) return 1;
    vis[t] = 0;
    return 0;
}

void work()
{
    dfs( 1 , 1 );
    rep(i,1,n) printf("%d%c",q[i],i==n?'\n':' ');
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
