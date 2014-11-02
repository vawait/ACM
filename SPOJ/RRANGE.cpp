/*
 * Author:  vawait
 * Created Time:  2014/11/2 19:06:47
 * Problem: SPOJ_RRANGE
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
int n , m , q , l[1100] , r[1100];

void init()
{
    scanf("%d%d%d",&n,&m,&q);
    rep(i,1,m) scanf("%d%d",&l[i],&r[i]);
}

void work()
{
    int L , R , x , y;
    while ( q -- ) {
        lint ans = 0;
        scanf("%d%d",&x,&y);
        rep(i,1,m) {
            L = max( x , l[i] );
            R = min( y , r[i] );
            if ( L > R ) continue;
            L -= l[i] - 1;
            R -= l[i] - 1;
            ( ans += lint( L + R ) * ( R - L + 1 ) / 2 ) %= 10000;
        }
        cout << ans << endl;
    }
}

int main()
{
    init();
    work();
    return 0;
}
