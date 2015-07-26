/*
 * Author:  vawait
 * Created Time:  2015/7/26 16:30:55
 * Problem: HDU4212 Shut the Box
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
#define two(x) ( 1 << ( x - 1 ) )
#define sqr(x) ((x) * (x))
typedef long long lint;
int n , m , ans , now = 1 , nex = 0 , a[40] , sum[1<<22];
bool f[2][1<<22];
vector < int > g[70];

void calc(int nn,int v,int sum)
{
    g[sum].pb( v );
    if ( sum > 22 || nn > n ) return;
    calc( nn + 1 , v , sum );
    if ( nn ) calc( nn + 1 , v | two( nn ) , sum + nn );
}

void init()
{
    ans = 0;
    rep(i,0,60) g[i].clear();
    calc( 1 , 0 , 0 );
    rep(i,1,m) scanf("%d",&a[i]);
}

void work()
{
    int ans = 0;
    n = ( 1 << n ) - 1;
    clr( f[now] , 0 );
    f[now][0] = 1;
    rep(i,1,n) sum[i] = sum[i>>1] + ( i & 1 );
    rep(j,1,m) {
        clr( f[nex] , 0 );
        int x = a[j];
        rep(i,0,n) if ( f[now][i] )
            red(k,g[x].size()-1,0) {
                if ( ( i & g[x][k] ) == 0 ) f[nex][i|g[x][k]] = 1; 
            }
        swap( now , nex );
        rep(i,0,n) if ( f[now][i] ) ans = max( ans , sum[i] );
    }
    cout << ans << endl;
}

int main()
{
    int t = 0;
    while ( scanf("%d%d",&n,&m) && n ) {
        printf("Game %d: ",++t);
        init();
        work();
    }
    return 0;
}
