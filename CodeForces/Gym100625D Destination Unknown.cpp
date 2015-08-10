/*
 * Author:  vawait
 * Created Time:  2015/8/9 14:42:55
 * Problem: Gym100625D Destination Unknown
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
int n , m , s , G , H , d[2100] , d2[2100] , vis[2100];
int sum , que[2100];
vector < pair < int , int > > g[2100];

void init()
{
    int x , y , dd;
    scanf("%d%d%d",&n,&m,&sum);
    scanf("%d%d%d",&s,&G,&H);
    rep(i,1,n) g[i].clear();
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&dd);
        g[x].pb( mp( y , dd ) );
        g[y].pb( mp( x , dd ) );
    }
    rep(i,1,sum) scanf("%d",&que[i]);
}

void spfa(int s,int dis)
{
    queue < int > q;
    q.push( s );
    clr( d , 1 );
    d[s] = dis;
    while ( !q.empty() ) {
        int x = q.front() , y;
        q.pop(); vis[x] = 0;
        red(i,g[x].size()-1,0) {
            y = g[x][i].x;
            if ( d[x] + g[x][i].y < d[y] ) {
                d[y] = d[x] + g[x][i].y;
                if ( !vis[y] ) vis[y] = 1 , q.push( y );
            }
        }
    }
}

void work()
{
    spfa( s , 0 );
    rep(i,1,n) d2[i] = d[i];
    if ( d[H] > d[G] ) swap( H , G );
    spfa( G , d[G] );
    
    s = 0;
    rep(i,1,sum) if ( d[que[i]] < d[n+1] && d[que[i]] == d2[que[i]] ) que[++s] = que[i];
    sort( que + 1 , que + 1 + s );
    rep(i,1,s) printf("%d%c",que[i],i==s?'\n':' ');
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
