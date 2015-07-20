/*
 * Author:  vawait
 * Created Time:  2015/7/20 15:06:22
 * Problem: HDU4149 Magic Potion
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
int a[100] , b[10][10] , c[10][10]  , d[40][10] , ans[100];

void init()
{
    clr( ans , 0 );
    rep(i,1,9) scanf("%d",&a[i]);
    rep(i,1,8)
        rep(j,1,8) b[i][j] = a[i] ^ a[j];
}

bool dfs(int k,int p)
{
    if ( k > 30 ) return 1;
    rep(i,1,8)
        rep(j,1,8) c[i][j] = ( b[i][j] >> k ) & 1;
    d[k][1] = p;
    rep(i,2,8) d[k][i] = c[1][i] ^ d[k][1];
    rep(i,1,8)
        rep(j,1,8) if ( ( d[k][i] ^ d[k][j] ) != c[i][j] ) return 0;
    
    lint sum = 0;
    rep(i,1,8) sum += ( ans[i] ^ ( d[k][i] << k ) );
    int now = ( ( sum ^ a[9] ) >> k ) & 1;
    rep(i,1,8) if ( ( now ^ ( ( a[i] >> k ) & 1 ) ) != d[k][i] ) return 0;
    rep(i,1,8) ans[i] ^= ( d[k][i] << k );
    return 1;
}

void work()
{
    lint sum = 0;
    rep(i,0,30) if ( !dfs( i , 0 ) ) dfs( i , 1 );
    rep(i,1,8) sum += ans[i];
    sum ^= a[9];
    cout << sum << endl;
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
