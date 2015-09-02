/*
 * Author:  vawait
 * Created Time:  2015/9/2 12:39:16
 * Problem: Gym100339I Sum vs Product
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
lint n , ans = 0 , f[510][510];

void init()
{
    cin >> n;
    rep(i,1,500) f[i][0] = 1;
    rep(i,1,500) 
        rep(j,1,500) f[i][j] = min( f[i][j-1] * i , 10001000LL );
}

void dfs(int m,int k,lint s,lint p)
{
    if ( k > 1 && p > s ) return;
    if ( m > n ) {
        if ( s == p ) ans ++;
        return;
    }
    rep(i,k,500) {
        if ( p * f[i][n-m+1] > s + 500 * ( n - m + 1 ) ) break;
        dfs( m + 1 , i , s + i , p * i );
    }
}

void work()
{
    dfs( 1 , 1 , 0 , 1 );
    cout << ans << endl;
}

int main()
{
    freopen("sump.in","r",stdin);
    freopen("sump.out","w",stdout);
    init();
    work();
    return 0;
}
