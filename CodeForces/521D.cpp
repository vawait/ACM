/*
 * Author:  vawait
 * Created Time:  2015/3/21 14:58:04
 * Problem: CodeForces_521D
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
const int maxn = 101000;
lint a[maxn];
int n , m , k , t[maxn] , p[maxn] , b[maxn];
int s , sum , mx[maxn] , num[maxn];
pair < long double , int > g[maxn] , q[maxn];

void init()
{
    s = sum = 0;
    clr( mx , 0 );
    rep(i,1,k) scanf("%I64d",&a[i]);
    rep(i,1,n) {
        scanf("%d%d%d",&t[i],&p[i],&b[i]);
        if ( t[i] == 1 && mx[p[i]] < b[i] ) mx[p[i]] = b[i] , num[p[i]] = i;
        if ( t[i] == 2 ) q[++s] = mp( b[i] , i );
        if ( t[i] == 3 ) g[++sum] = mp( log( 1.0 * b[i] ) , i );
    }
    rep(i,1,k) if ( mx[i] > a[i] ) q[++s] = mp( mx[i] - a[i] , num[i] );
}

void work()
{
    int x;
    if ( s ) {
        sort( q + 1 , q + s + 1 );
        red(i,s,1) {
            x = p[q[i].y];
            g[++sum] = mp( log( q[i].x + a[x] ) - log( a[x] ) , q[i].y );
            a[x] += q[i].x + 0.00001;
        }
    }
    if ( sum ) {
        s = 0;
        sort( g + 1 , g + 1 + sum );
        rep(i,max(1,sum-m+1),sum) q[++s] = mp( t[g[i].y] , g[i].y );
        sort( q + 1 , q + s + 1 );
    }
    printf("%d\n",s);
    rep(i,1,s) printf("%d ",q[i].y);
}

int main()
{
    while ( cin >> k >> n >> m ) {
        init();
        work();
    }
    return 0;
}
