/*
 * Author:  vawait
 * Created Time:  2015/7/13 12:24:12
 * Problem: BZOJ2435 [Noi2011]道路修建
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
const int maxn = 1001000;
int n , sum[maxn] , a[maxn] , b[maxn] , c[maxn] , fa[maxn];
vector < int > g[maxn];

void init()
{
    scanf("%d",&n);
    rep(i,2,n) {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        g[a[i]].pb( b[i] );
        g[b[i]].pb( a[i] );
    }
}

void dfs(int t)
{
    sum[t] = 1;
    red(i,g[t].size()-1,0) if ( fa[t] != g[t][i] ) {
        fa[g[t][i]] = t;
        dfs( g[t][i] );
        sum[t] += sum[g[t][i]];
    }
}

void work()
{
    lint ans = 0;
    dfs( 1 );
    rep(i,2,n) ans += (lint)c[i] * abs( n - 2 * sum[ fa[a[i]] == b[i] ? a[i] : b[i] ] );
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
