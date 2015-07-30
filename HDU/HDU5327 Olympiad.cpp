/*
 * Author:  vawait
 * Created Time:  2015/7/30 12:03:45
 * Problem: HDU5327 Olympiad
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
const int n = 100000;
int sum[n+10] , v[10];

int calc(int t)
{
    clr( v , 0 );
    while ( t ) {
        int x = t % 10;
        if ( v[x] ) return 0;
        v[x] = 1;
        t /= 10;
    }
    return 1;
}

void init()
{
    sum[0] = 1;
    rep(i,1,n) sum[i] = sum[i-1] + calc( i );
}

void work()
{
    int t , l , r;
    for ( cin >> t; t; t-- ) {
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }
}

int main()
{
    init();
    work();
    return 0;
}
