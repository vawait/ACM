/*
 * Author:  vawait
 * Created Time:  2015/2/3 1:00:54
 * Problem: CodeForces_512B
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
int n , l[400] , c[400];

int gcd(int x,int y)
{
    return y ? gcd( y , x % y ) : x;
}

void init()
{
    rep(i,1,n) scanf("%d",&l[i]);
    rep(i,1,n) scanf("%d",&c[i]);
}

void work()
{
    int now = 0 , nex = 1 , y;
    map < int , int > h[2];
    map < int , int >::iterator it;
    h[now].clear();
    h[now][0] = 0;
    rep(i,1,n) {
        h[nex] = h[now];
        for ( it = h[now].begin(); it != h[now].end(); it++) {
            y = gcd( l[i] , it->first );
            if ( h[nex].count( y ) ) h[nex][y] = min( h[nex][y] , it->second + c[i] );
            else h[nex][y] = it->second + c[i];
        }
        swap( now , nex );
    }
    if ( h[now].count( 1 ) ) printf("%d\n",h[now][1]);
    else puts("-1");
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
