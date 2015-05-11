/*
 * Author:  vawait
 * Created Time:  2015/5/11 13:40:24
 * Problem: CodeForces_543A
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
int n , m , b , mod , f[510][510] , a[510];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    clr( f , 0 );
    f[0][0] = 1;
}

void work()
{
    rep(k,1,n) {
        rep(i,1,m)
            rep(j,0,b) if ( a[k] <= j )
                ( f[i][j] += f[i-1][j-a[k]] ) %= mod;
    }
    int ans = 0;
    rep(i,0,b) ( ans += f[m][i] ) %= mod;
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m >> b >> mod ) {
        init();
        work();
    }
    return 0;
}
