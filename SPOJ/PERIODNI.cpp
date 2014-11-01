/*
 * Author:  vawait
 * Created Time:  2014/11/1 20:59:53
 * Problem: SPOJ_PERIODNI
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
const lint mm = 1e9 + 7;
const int maxn = 510;
int sum = 0 , n , m , a[maxn] , h[maxn] , len[maxn] , c[maxn][maxn];
lint fac[1001000] , fn[1001000] , f[maxn][maxn];
vector < int > g[maxn];

lint km(lint a,int n) 
{
    lint s = 1;
    while ( n ) {
        if ( n & 1 ) ( s *= a ) %= mm;
        ( a *= a ) %= mm;
        n >>= 1;
    }
    return s;
}

lint C(lint n,lint m)
{
    return ( fac[n] * fn[m] % mm ) * fn[n-m] % mm;
}

void build(int t,int l,int r)
{
    int mx = 100000000 , L = l , id = ++sum;
    rep(i,l,r) mx = min( mx , a[i] );
    g[t].pb( id );
    len[id] = r - l + 1;
    h[id] = mx;
    rep(i,l,r) a[i] -= mx;
    rep(i,l,r) if ( !a[i] ) {
        if ( L < i ) build( id , L , i - 1 );
        L = i + 1;
    }
    if ( a[r] ) build( id , L , r );
}

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) g[i].clear();
    fac[0] = fn[0] = 1;
    rep(i,1,1000000) fac[i] = i * fac[i-1] % mm , fn[i] = km( fac[i] , mm - 2 );
    build( 0 , 1 , n );
}

void dfs(int t)
{
    int y;
    f[t][0] = 1;
    red(i,g[t].size()-1,0) {
        dfs( y = g[t][i] );
        red(j,len[t],1)
            rep(k,1,j) ( f[t][j] += f[t][j-k] * f[y][k] ) %= mm;
    }
    red(i,len[t],1)
        red(j,i,1) {
            y = len[t] - ( i - j );
            if ( y < j || h[t] < j ) continue;
            ( f[t][i] += ( f[t][i-j] * C( y , j ) % mm ) * ( fac[h[t]] * fn[h[t]-j] % mm ) ) %= mm;
        }
}

void work()
{
    dfs( 1 );
    cout << f[1][m] << endl;
}

int main()
{
    init();
    work();
    return 0;
}
