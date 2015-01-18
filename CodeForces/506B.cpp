/*
 * Author:  vawait
 * Created Time:  2015/1/18 21:44:58
 * Problem: CodeForces_506B
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
const int maxn = 100000;
int tim = 0 , n , m , low[maxn+100] , z[maxn+100] , f[maxn+100];
int va[maxn+100] , vb[maxn+100] , sum[maxn+100] , visit[maxn+100];
vector < int > a[maxn+100];

int find(int t)
{
    if ( f[t] == t ) return t;
    return f[t] = find( f[t] );
}

void dfs(int t)
{
    int y;
    low[t] = ++tim;
    z[t] = 1;
    red(i,a[t].size()-1,0) {
        y = a[t][i];
        if ( !low[y] ) dfs( y );
        y = find( y );
        if ( z[y] && low[y] < low[t] ) {
            low[t] = low[y];
            f[find(t)] = y;
        }
    }
    z[t] = 0;
}

void init()
{
    int x , y;
    clr( z , 0 );
    clr( low , 0 );
    tim = 1;
    rep(i,1,n) f[i] = i;
    rep(i,1,m) {
        scanf("%d%d",&va[i],&vb[i]);
        a[va[i]].pb( vb[i] );
    }
}

void work()
{
    int ans = 0 , x , y;
    rep(i,1,n) if ( !low[i] ) dfs( i );
    clr( sum , 0 );
    rep(i,1,n) sum[find(i)] ++;
    rep(i,1,n) visit[i] = sum[find(i)] > 1;
    rep(i,1,m) {
        x = find( va[i] ) , y = find( vb[i] );
        if ( x != y ) {
            f[x] = y;
            visit[y] = max( visit[y] , visit[x] );
        }
    }
    
    clr( sum , 0 );
    rep(i,1,n) sum[find(i)] ++;
    rep(i,1,n) if ( sum[i] > 1 ) {
        ans += sum[i] - 1 + visit[i];
    }
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
