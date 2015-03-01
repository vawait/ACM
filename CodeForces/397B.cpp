/*
 * Author:  vawait
 * Created Time:  2015/2/28 13:52:18
 * Problem: CodeForces_397B
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
int n , l , r;

void init()
{
    scanf("%d%d%d",&n,&l,&r);
    if ( l <= n ) {
        r = min( r , n );
        r -= l;
        int x = n / ( l + r );
        if ( x * ( l + r ) != n ) x ++;
        if ( x <= n / l ) {
            puts("Yes");
            return;
        }
    }
    puts("No");
}

void work()
{
}

int main()
{
    int T;
    for ( cin >> T; T; T -- ) {
        init();
        work();
    }
    return 0;
}
