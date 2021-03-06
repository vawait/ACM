/*
 * Author:  vawait
 * Created Time:  2014/10/29 13:47:12
 * File Name: CodeChefLEMOVIE.cpp
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
int mx , n , m , a[300] , s[300];
lint f[202][202][202];

void init()
{
    int x;
    scanf("%d%d",&n,&m);
    clr( a , 0 );
    mx = 0;
    rep(i,1,n) scanf("%d",&x) , a[x] ++ , mx = max( mx , x );
    s[201] = 0;
    red(i,200,1) s[i] = s[i+1] + a[i];
    clr( f , 0 );
    f[0][0][0] = 1;
}

void work()
{
    rep(i,0,n-1)
        rep(j,0,mx)
            red(k,min(i,m),0) if ( f[i][j][k] ) {
                ( f[i+1][j][k] += f[i][j][k] * ( n - s[j+1] - i ) ) %= mm;
                rep(r,j+1,mx) if ( a[r] )
                    ( f[i+1][r][k+1] += f[i][j][k] * a[r] ) %= mm;
            }
    lint ans = 0;
    rep(i,0,mx)
        rep(j,0,m) ( ans += f[n][i][j] ) %= mm;
    cout << ans << endl;
}

int main()
{
    int t;
    for ( cin >> t; t; t -- ) {
        init();
        work();
    }
    return 0;
}
