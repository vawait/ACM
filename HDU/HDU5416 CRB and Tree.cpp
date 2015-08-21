/*
 * Author:  vawait
 * Created Time:  2015/8/20 12:07:49
 * Problem: HDU5416 CRB and Tree
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
int n , len[maxn] , sum[maxn];
vector < pair < int , int > > g[maxn];

void dfs(int t,int fa)
{
    sum[len[t]] ++;
    red(i,g[t].size()-1,0) if ( g[t][i].x != fa ) {
        len[g[t][i].x] = len[t] ^ g[t][i].y;
        dfs( g[t][i].x , t );
    }
}

void init()
{
    int x , y , d;
    scanf("%d",&n);
    rep(i,1,n) g[i].clear();
    rep(i,2,n) {
        scanf("%d%d%d",&x,&y,&d);
        g[x].pb( mp( y , d ) );
        g[y].pb( mp( x , d ) );
    }
    clr( sum , 0 );
    len[1] = 0;
    dfs( 1 , 0 );
}

void work()
{
    int x , Q;
    scanf("%d",&Q);
    while ( Q-- ) {
        scanf("%d",&x);
        lint ans = 0;
        rep(i,1,n) ans += sum[len[i] ^ x];
        if ( !x ) ans += n;
        cout << ans / 2 << endl;
    }
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
