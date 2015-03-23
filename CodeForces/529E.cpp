/*
 * Author:  vawait
 * Created Time:  2015/3/22 16:59:13
 * Problem: CodeForces_529E
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
int n , m , q , a[5100];
set < pair < int , int > > h;

void init()
{
    h.clear();
    rep(i,1,n) {
        scanf("%d",&a[i]);
        rep(j,1,m) h.insert( mp( a[i] * j , j ) );
    }
    h.insert( mp( 0 , 0 ) );
    scanf("%d",&q);
}

void work()
{
    int x , y;
    while ( q -- ) {
        int ans = 10000;
        scanf("%d",&x);
        rep(i,1,n)
            rep(j,1,m) if ( a[i] * j <= x ) {
                y = x - a[i] * j;
                rep(k,0,m-j) if ( h.find( mp( y , k ) ) != h.end() )
                    ans = min( ans , k + j );
            }
        printf("%d\n",ans>100?-1:ans);
    }
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
