/*
 * Author:  vawait
 * Created Time:  2015/3/22 15:28:04
 * Problem: CodeForces_367E
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
const int mm = 1e9 + 7;
int n , m , x , now = 1 , nex = 0;
int f[2][410][410];

void init()
{
    clr( f[now] , 0 );
    f[now][0][0] = 1;
}

void up(int &x,int y)
{
    x += y;
    if ( x >= mm ) x -= mm;
}

void work()
{
    if ( n > m ) {
        puts("0");
        return;
    }
    
    rep(k,1,m) {
        rep(i,0,n)
            rep(j,0,n) f[nex][i][j] = 0;
        red(i,min(n,k),0)
            rep(j,0,i) {
                up( f[nex][i+1][j] , f[now][i][j] );
                up( f[nex][i+1][j+1] , f[now][i][j] );
                if ( k != x ) {
                    up( f[nex][i][j] , f[now][i][j] );
                    up( f[nex][i][j+1] , f[now][i][j] );
                }
            }
        swap( now , nex );
    }
    lint ans = f[now][n][n];
    rep(i,1,n) ( ans *= i ) %= mm;
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m >> x ) {
        init();
        work();
    }
    return 0;
}
