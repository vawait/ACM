/*
 * Author:  vawait
 * Created Time:  2015/8/8 13:17:39
 * Problem: Gym100589G Count Permutations
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
typedef unsigned long long lint;
int n , m ; 
lint f[1<<15][15];

void init()
{
    scanf("%d%d",&n,&m);
    n --;
    clr( f , 0 );
    rep(i,0,n) f[1<<i][i] = 1;
}

void work()
{
    int mm = ( 1 << ( n + 1 ) ) - 1;
    rep(i,1,mm) 
        rep(j,0,n) if ( f[i][j] ) {
            rep(k,max(0,j-m),j+m) if ( k <= n && k != j && ( ( ( i >> k ) & 1 ) == 0 ) )
                f[i|(1<<k)][k] += f[i][j];
        }
    lint ans = 0;
    rep(i,0,n) ans += f[mm][i];
    cout << ans << endl;
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
