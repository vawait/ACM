/*
 * Author:  vawait
 * Created Time:  2015/8/11 12:58:56
 * Problem: HDU5379 Mahjong tree
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
const lint mod = 1e9 + 7;
const int maxn = 201000;
int n , sum[maxn] ; 
lint f[maxn] , fn[maxn];
vector < int > g[maxn];

void init()
{
    int x , y;
    scanf("%d",&n);
    fn[0] = 1;
    rep(i,1,n) g[i].clear() , fn[i] = fn[i-1] * i % mod;
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
}

void dfs(int t,int fa)
{
    int y = 0 , s = 0 , s2 = 0;
    sum[t] = 1;
    f[t] = 1;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa ) {
        dfs( y , t );
        sum[t] += sum[y];
        ( f[t] *= f[y] ) %= mod;
        if ( sum[y] > 1 ) s ++; else s2 ++;
    }
    if ( s > 2 ) f[t] = 0; else if ( s == 0 ) {
        f[t] = fn[s2];
    } else {
        f[t] = f[t] * fn[s2] * 2LL % mod;
    }
    //printf("%d %d %d\n",t,s,s2);
}

void work()
{
    if ( n == 1 ) {
        puts("1");
        return;
    }
    dfs( 1 , 0 );
    lint ans = 1 , s = 0 , s1 = 1;
    red(i,g[1].size()-1,0) {
        if ( sum[g[1][i]] == 1 ) s1 ++; else s ++;
        ( ans *= f[g[1][i]] ) %= mod;
    }
    cout << f[1] * 2 % mod << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
