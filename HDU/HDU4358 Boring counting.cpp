/*
 * Author:  vawait
 * Created Time:  2015/8/2 12:42:14
 * Problem: HDU4358 Boring counting
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
const int maxn = 101000;
int n , m , Q , num , L[maxn] , R[maxn] , w[maxn] , A[maxn];
int sum[maxn] , ans , l , r , Ans[maxn];
vector < int > g[maxn];
vector < int > b;

struct nodd
{
    int l , r , k , id;
} a[maxn];

bool cmp(const nodd &a,const nodd &b)
{
    return a.k < b.k || a.k == b.k && a.r < b.r;
}

void dfs(int t,int fa)
{
    L[t] = ++num;
    A[num] = t;
    red(i,g[t].size()-1,0) if ( g[t][i] != fa )
        dfs( g[t][i] , t );
    R[t] = num;
}

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    rep(i,1,n) g[i].clear();
    b.clear();
    rep(i,1,n) scanf("%d",&w[i]) , b.pb( w[i] );
    sort( b.begin() , b.end() );
    rep(i,1,n) w[i] = lower_bound( b.begin() , b.end() , w[i] ) - b.begin();
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    num = 0;
    dfs( 1 , 0 );
    scanf("%d",&Q);
    int nn = sqrt( n * 1.0 ) + 5;
    rep(i,1,Q) {
        scanf("%d",&x);
        a[i].l = L[x] , a[i].r = R[x];
        a[i].k = L[x] / nn , a[i].id = i;
    }
    sort( a + 1 , a + Q + 1 , cmp );
    clr( sum , 0 );
}

void add(int t)
{
    if ( sum[t] == m ) ans --;
    sum[t] ++;
    if ( sum[t] == m ) ans ++;
}

void del(int t)
{
    if ( sum[t] == m ) ans --;
    sum[t] --;
    if ( sum[t] == m ) ans ++;
}

void work()
{
    ans = 0;
    l = 1 , r = 0;
    add( w[A[++r]] );
    rep(i,1,Q) {
        while ( r < a[i].r ) add( w[A[++r]] );
        while ( r > a[i].r ) del( w[A[r--]] );
        while ( l > a[i].l ) add( w[A[--l]] );
        while ( l < a[i].l ) del( w[A[l++]] );
        Ans[a[i].id] = ans;
    }
    rep(i,1,Q) printf("%d\n",Ans[i]);
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        if ( i > 1 ) puts("");
        printf("Case #%d:\n",i);
        init();
        work();
    }
    return 0;
}
