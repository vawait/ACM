/*
 * Author:  vawait
 * Created Time:  2014/12/27 19:20:54
 * Problem: HDU_5151
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
int n , a[110];
lint f[110][110][2] , s[110][110][2];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    clr( f , 0 );
    clr( s , 0 );
    f[1][1][1] = 1;
    rep(i,1,n) s[1][i][1] = 1;
}

void work()
{
    rep(i,2,n) {
        rep(j,1,i) {
            f[i][j][0] = ( s[i-1][j-1][1] + s[i-1][j-1][0] ) % mm;
            f[i][j][1] = ( s[i-1][i][1] - s[i-1][j-1][1] ) % mm;
            if ( a[i] == a[i-2] ) {
                ( f[i][j][1] += s[i-1][i][0] - s[i-1][j-1][0] ) %= mm;
            }
        }
        rep(j,1,n)
            rep(k,0,1) s[i][j][k] = s[i][j-1][k] + f[i][j][k];
    }
    lint ans = 0;
    rep(i,1,n)
        rep(j,0,1) ( ans += f[n][i][j] ) %= mm;
    ( ans += mm ) %= mm;
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
