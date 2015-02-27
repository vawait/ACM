/*
 * Author:  vawait
 * Created Time:  2015/2/27 18:26:30
 * Problem: CodeForces_337D
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
int n , m , D , d[maxn] , p[maxn] , d2[maxn];
vector < int > a[maxn];

void init()
{
    int x , y;
    scanf("%d%d%d",&n,&m,&D);
    rep(i,1,m) scanf("%d",&p[i]);
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        a[x].pb( y );
        a[y].pb( x );
    }
}

int bfs(int v)
{
    queue < int > q;
    clr( d , 1 );
    d[v] = 0;
    q.push( v );
    while ( !q.empty() ) {
        int x = q.front() , y;
        q.pop();
        red(i,a[x].size()-1,0) if ( d[x] + 1 < d[y=a[x][i]] ) {
           d[y] = d[x] + 1;
           q.push( y );
        }
    }
    int mx = -1 , ans;
    rep(i,1,m) if ( d[p[i]] > mx ) mx = d[p[i]] , ans = p[i];
    return ans;
}

void work()
{
    int x = bfs( p[1] ) , y = bfs( x ) , ans = 0;
    rep(i,1,n) d2[i] = d[i];
    bfs( y );
    rep(i,1,n) if ( d[i] <= D && d2[i] <= D ) ans ++;
    printf("%d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
