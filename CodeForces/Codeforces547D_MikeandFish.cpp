/*
 * Author:  vawait
 * Created Time:  2015/5/28 20:48:21
 * Problem: Codeforces547D Mike and Fish
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
int n , a[maxn] , b[maxn] , ans[maxn];
vector < int > g[maxn];

void init()
{
    int x , y;
    clr( a , 0 );
    clr( b , 0 );
    clr( ans , 0 );
    rep(i,0,n) g[i].clear();
    rep(i,1,n) {
        scanf("%d%d",&x,&y);
        if ( a[x] ) 
            g[i].pb( a[x] ) , g[a[x]].pb( i ) , a[x] = 0;
        else
            a[x] = i;
        if ( b[y] ) 
            g[i].pb( b[y] ) , g[b[y]].pb( i ) , b[y] = 0;
        else
            b[y] = i;
    }
}

void dfs(int t,int m)
{
    ans[t] = m;
    red(i,g[t].size()-1,0) if ( !ans[g[t][i]] )
        dfs( g[t][i] , 3 - m );
}

void work()
{
    rep(i,1,n) if ( !ans[i] ) dfs( i , 1 );
    rep(i,1,n) printf("%c",ans[i]==1?'b':'r');
    puts("");
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
