/*
 * Author:  vawait
 * Created Time:  2015/8/2 16:28:55
 * Problem: HDU4343 Interval query
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
const int maxn = 201000;
int n , m , num , f[maxn<<1][20];
int al[maxn] , ar[maxn];
pair < int , int > a[maxn];
vector < int > g;

void init()
{
    g.clear();
    rep(i,1,n) {
        scanf("%d%d",&a[i].x,&a[i].y);
        g.pb( a[i].x );
        g.pb( a[i].y );
    }
    sort( a + 1 , a + n + 1 );
    rep(i,1,m) {
        scanf("%d%d",&al[i],&ar[i]);
        g.pb( al[i] );
        g.pb( ar[i] );
    }
    sort( g.begin() , g.end() );
    g.resize( unique( g.begin() , g.end() ) - g.begin() );
    rep(i,1,n) {
        a[i].x = lower_bound( g.begin() , g.end() , a[i].x ) - g.begin() + 1;
        a[i].y = lower_bound( g.begin() , g.end() , a[i].y ) - g.begin() + 1;
    }
    num = g.size();
}

void work()
{
    int mx = num + 1;
    rep(i,0,19) f[num+1][i] = num + 1;
    red(i,num,1) {
        while ( n && a[n].x >= i ) mx = min( mx , a[n--].y );
        f[i][0] = mx;
        rep(j,1,19) f[i][j] = f[f[i][j-1]][j-1];
    }
    rep(i,1,m) {
        int l = lower_bound( g.begin() , g.end() , al[i] ) - g.begin() + 1;
        int r = lower_bound( g.begin() , g.end() , ar[i] ) - g.begin() + 1;
        int ans = 0;
        red(j,19,0) if ( f[l][j] <= r ) ans += ( 1 << j ) , l = f[l][j];
        printf("%d\n",ans);
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
