/*
 * Author:  vawait
 * Created Time:  2015/1/24 1:16:42
 * Problem: CodeForces_507D
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
lint n , m , mm , f[1100][110];

void init()
{
    clr( f , 0 );
}

void work()
{
    int x = 1;
    rep(i,0,n) {
        f[i+1][0] = f[i][0] * 10 % mm;
        rep(k,1,9) ( f[i+1][(x*k)%m] += 1 ) %= mm;
        rep(j,1,m)
            rep(k,0,9) {
                ( f[i+1][(j+k*x)%m] += f[i][j] ) %= mm;
            }
        ( x *= 10 ) %= m;
    }
    cout << ( f[n][0] - f[n-1][0] + mm ) % mm << endl;
}

int main()
{
    while ( cin >> n >> m >> mm ) {
        init();
        work();
    }
    return 0;
}
