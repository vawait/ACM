/*
 * Author:  vawait
 * Created Time:  2015/8/11 14:18:32
 * Problem: HDU5378 Leader in Tree Land
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
const lint mod = 1e9 + 7;
int n , m , sv[1010] , fa[1010];
lint sum[1010] , f[1010][1010] , fn[1010] , c[1010][1010];
vector < int > g[1010];

void find(int t)
{
    int y;
    sum[t] = 0;
    fn[t] = 1;
    red(i,g[t].size()-1,0) if ( ( y = g[t][i] ) != fa[t] ) {
        fa[y] = t;
        find( y );
        sum[t] += sum[y];
        ( fn[t] *= c[sum[t]][sum[y]] ) %= mod;
    }
    sum[t] ++;
}

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    rep(i,1,n) g[i].clear();
    rep(i,2,n) {
        scanf("%d%d",&x,&y);
        g[x].pb( y );
        g[y].pb( x );
    }
    rep(i,0,n) c[i][0] = 1;
    rep(i,1,n)
        rep(j,1,i) c[i][j] = ( c[i-1][j] + c[i-1][j-1] ) % mod;
    clr( f , 0 );
    fa[1] = 0;
    find( 1 );
    f[0][0] = 1;
}

void work()
{
    rep(i,1,n) {
        red(j,n,0) f[i][j] = ( f[i-1][j] * ( sum[i] - 1 ) + ( j ? f[i-1][j-1] : 0 ) ) % mod * fn[i] % mod;
    }
    cout << f[n][m] << endl;
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
