/*
 * Author:  vawait
 * Created Time:  2015/8/31 22:37:01
 * Problem: Gym100341G TV Show
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
const int maxn = 200;
int a , b , c , sum = 0 , x[maxn] , y[maxn] , z[maxn];
int h[maxn] , vh[maxn] , ans[maxn] , use[maxn];
vector < int > g[maxn];

bool ok(int i,int j)
{
    int a[3] = { x[i] - x[j] , y[i] - y[j] , z[i] - z[j] };
    rep(i,0,2) a[i] = abs( a[i] );
    sort( a , a + 3 );
    rep(i,0,2) if ( a[i] != i ) return 0;
    return 1;
}

void init()
{
    scanf("%d%d%d",&a,&b,&c);
    rep(i,1,a)
        rep(j,1,b) rep(k,1,c) {
            x[++sum] = i ; y[sum] = j ; z[sum] = k;
        }
    rep(i,1,sum)
        rep(j,1,sum) if ( ok( i , j ) ) 
            g[i].pb( j );
    rep(i,1,sum) {
        h[i] = g[i].size();
        vh[h[i]] ++;
    }
}

bool dfs(int t,int m)
{
    ans[m] = t;
    if ( m == sum ) {
        puts("YES");
        rep(i,1,sum) {
            int p = ans[i];
            printf("%d %d %d\n",x[p],y[p],z[p]);
        }
        return 1;
    }
    if ( vh[0] || vh[1] > 1 + ( h[t] == 1 ) ) return 0;
    int y;
    use[t] = 1; --vh[h[t]];
    red(i,g[t].size()-1,0) if ( !use[y=g[t][i]] ) {
        --vh[h[y]];
        h[y] --;
        ++vh[h[y]];
    }
    red(i,g[t].size()-1,0) if ( !use[g[t][i]] && dfs( g[t][i] , m + 1 ) )
        return 1;
    red(i,g[t].size()-1,0) if ( !use[y=g[t][i]] ) {
        --vh[h[y]];
        h[y] ++;
        ++vh[h[y]];
    }
    use[t] = 0; ++vh[h[t]];
    return 0;
}

void work()
{
    if ( !dfs( 1 , 1 ) ) puts("NO");
}

int main()
{
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    init();
    work();
    return 0;
}
