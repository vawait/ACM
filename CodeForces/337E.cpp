/*
 * Author:  vawait
 * Created Time:  2015/2/28 10:03:13
 * Problem: CodeForces_337E
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
lint n , a[20] , f[20] , b[20] , fn[20] , ans;
int sum = 0 , vis[1001000] , prime[1001000];

void init()
{
    rep(i,2,1000000) {
        if ( !vis[i] ) prime[++sum] = i;
        for ( int j = 1; j <= sum && i * prime[j] <= 1000000; j ++ ) {
            vis[i*prime[j]] = 1;
            if ( i % prime[j] == 0 ) break;
        }
    }
    
    clr( f , 0 );
    rep(i,1,n) cin >> a[i];
    sort( a + 1 , a + n + 1 );
    rep(i,1,n) {
        b[i] = a[i];
        lint x = a[i];
        rep(j,1,sum) {
            if ( prime[j] > x ) break;
            while ( x % prime[j] == 0 ) x /= prime[j] , f[i] ++;
        }
        if ( x > 1 ) f[i] ++;
        vis[i] = ( f[i] == 1 );
        fn[i] = f[i];
    }
    ans = 1000000;
}

void dfs(int nn,lint sum,int v)
{
    if ( nn > n ) {
        if ( sum < ans ) ans = sum;
        return;
    }
    rep(i,nn+1,n) if ( b[i] % a[nn] == 0 ) {
        b[i] /= a[nn];
        fn[i] -= f[nn];
        dfs( nn + 1 , sum + ( vis[nn] == 1 ? 1 : fn[nn] + 1 ) , v );
        b[i] *= a[nn];
        fn[i] += f[nn];
    }
    if ( nn == n ) v = 0;
    dfs( nn + 1 , sum + ( vis[nn] == 1 ? 1 : fn[nn] + 1 ) + v , 0 );
}

void work()
{
    dfs( 1 , 0 , 1 );
    cout << ans << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
