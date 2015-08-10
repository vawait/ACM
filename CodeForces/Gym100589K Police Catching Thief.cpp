/*
 * Author:  vawait
 * Created Time:  2015/8/8 14:32:46
 * Problem: Gym100589K Police Catching Thief
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
const int maxn = 201000;
int n , m , S , T , vis[maxn] , spo , po[maxn] , sbo , bo[maxn];
lint d[maxn] , d2[maxn];
vector < pair < int , int > > g[maxn];
queue < int > q;

void init()
{
    int x , y , dd;
    rep(i,1,n) g[i].clear();
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&dd);
        x ++; y ++; dd *= 2;
        g[x].pb( mp( y , dd ) );
        g[y].pb( mp( x , dd ) );
    }
    scanf("%d",&spo);
    rep(i,1,spo) scanf("%d",&po[i]) , po[i] ++;
    scanf("%d",&sbo);
    rep(i,1,sbo) scanf("%d",&bo[i]) , bo[i] ++;
    scanf("%d%d",&S,&T);
    S ++; T ++;
}

void spfa()
{
    int x , y;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        vis[x] = 0;
        red(i,g[x].size()-1,0) {
            y = g[x][i].x;
            if ( d[x] + g[x][i].y < d[y] ) {
                d[y] = d[x] + g[x][i].y;
                if ( !vis[y] ) q.push( y ) , vis[y] = 1;
            }
        }
    }
}

void work()
{
    lint mx;
    clr( d , 1 );
    clr( vis , 0 );
    while ( !q.empty() ) q.pop();
    q.push( T );
    d[T] = 0;
    spfa();
    mx = d[S];
    rep(i,1,spo) if ( d[po[i]] <= mx ) {
        puts("-1");
        return;
    }
    rep(i,1,sbo) d2[bo[i]] = d[bo[i]] / 2;
    clr( d , 1 );
    rep(i,1,sbo) {
        int x = bo[i];
        d[x] = d2[x];
        q.push( x );
        vis[x] = 1;
    }
    spfa();
    rep(i,1,spo) if ( d[po[i]] <= mx ) {
        puts("-1");
        return;
    }
    cout << mx / 2 << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
