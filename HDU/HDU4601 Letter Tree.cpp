/*
 * Author:  vawait
 * Created Time:  2015/9/14 15:10:39
 * Problem: HDU4601 Letter Tree
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
const int maxn = 101000;
int n , sum , L[maxn] , R[maxn] , dep[maxn] , pos[maxn];
lint fn[maxn];
int ans[maxn] , ax[maxn] , am[maxn];
vector < pair < int , int > > g[maxn];
pair < int , int > ask[maxn] , node[maxn];

struct Trie
{
    int sum , sr , y , a[maxn][26] ;
    int rank[maxn] , sa[maxn] , fa[maxn] , dep[maxn] , st[maxn][20];
    lint hash[maxn];
    void dfs(int t) {
        rank[t] = ++ sr;
        sa[sr] = t;
        rep(i,0,25) if ( y = a[t][i] ) {
            dep[y] = dep[t] + 1;
            hash[y] = ( hash[t] * 26 + i ) % mod;
            dfs( y );
        }
    }
    void calc() {
        dep[0] = 1;
        hash[sr=0] = 0;
        dfs( 0 );
        rep(i,1,sum) st[i][0] = fa[i];
        rep(j,1,17)
            rep(i,1,sum) st[i][j] = st[st[i][j-1]][j-1];
    }
    int newNode() {
        clr( a[++sum] , 0 );
        return sum;
    }
    int add(int p,int x) {
        if ( !a[p][x] ) {
            a[p][x] = newNode();
            fa[a[p][x]] = p;
        }
        return a[p][x];
    }
    void init() {
        sum = 0;
        clr( a[0] , 0 );
    }
} Tr;

struct zkw
{
    int a[270000] , m;
    void init() {
        for( m = 1; m - 2 < n; m <<= 1 );
        clr( a , 0 );
    }
    void cha(int l,int k) {
        l += m;
        a[l] = max( a[l] , k );
        for ( int i = l >> 1; i; i >>= 1 ) a[i] = max( a[i<<1] , a[i<<1|1] ); 
    }
    int ask(int l,int r) {
        int ans = 0;
        l += m - 1; r += m + 1;
        for ( ; l^r^1; l>>=1 , r>>=1 ) {
            if ( ~l&1 ) ans = max( ans , a[l^1] );
            if ( r&1 ) ans = max( ans , a[r^1] );
        }
        return ans;
    }
} T;

void init()
{
    int x , y;
    char c[2];
    scanf("%d",&n);
    rep(i,1,n) g[i].clear();
    sum = 0;
    T.init(); Tr.init();
    dep[1] = pos[1] = 0;
    fn[0] = 1;
    rep(i,1,n) fn[i] = fn[i-1] * 26LL % mod;
    rep(i,2,n) {
        scanf("%d%d%s",&x,&y,c);
        g[x].pb( mp( y , c[0] - 'a' ) );
        g[y].pb( mp( x , c[0] - 'a' ) );
    }
}

void dfs(int t,int fa)
{
    int y;
    L[t] = ++sum;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i].x ) != fa ) {
        dep[y] = dep[t] + 1;
        pos[y] = Tr.add( pos[t] , g[t][i].y );
        dfs( y , t );
    }
    R[t] = sum;
}

void work()
{
    int q , id , x , y;
    dfs( 1 , 0 );
    Tr.calc();
    rep(i,1,n) node[i] = mp( dep[i] , i );
    sort( node + 1 , node + n + 1 );
    
    scanf("%d",&q);
    rep(i,1,q) {
        scanf("%d%d",&ax[i],&am[i]);
        ask[i] = mp( dep[ax[i]] + am[i] , i );
    }
    sort( ask + 1 , ask + q + 1 );
    
    red(i,q,1) {
        while ( n && node[n].x >= ask[i].x ) {
            x = node[n--].y;
            T.cha( L[x] , Tr.rank[pos[x]] );
        }
        id = ask[i].y; x = ax[id];
        ans[id] = T.ask( L[x] , R[x] );
    }
    
    lint l , r;
    rep(i,1,q) if ( ans[i] ) {
        l = Tr.hash[pos[ax[i]]];
        y = Tr.sa[ans[i]];
        x = pos[ax[i]];
        red(j,17,0) if ( Tr.dep[Tr.st[y][j]] - Tr.dep[x] >= am[i] ) 
            y = Tr.st[y][j];
        
        r = Tr.hash[y];
        r -= l * fn[am[i]];
        r %= mod;
        ( r += mod ) %= mod;
        printf("%d\n",(int)r);
    } else {
        puts("IMPOSSIBLE");
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
