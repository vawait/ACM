/*
 * Author:  vawait
 * Created Time:  2014/12/30 22:58:43
 * Problem: CodeForces_500A
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
int n , m , a[100000] , v[100000];

void init()
{
    clr( v , 0 );
    v[1] = 1;
    rep(i,1,n-1) scanf("%d",&a[i]);
    rep(i,1,n-1) if ( v[i] ) v[a[i]+i] = 1;
}

void work()
{
    puts( v[m] ? "YES" : "NO" );
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
