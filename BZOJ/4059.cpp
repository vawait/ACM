/*
 * Author:  vawait
 * Created Time:  2015/5/13 16:10:04
 * Problem: BZOJ_4059
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
int n , a[maxn] , l[maxn] , r[maxn] , v[maxn*20];
int al , ar , as;
map < int , int > h;

void build(int t,int l,int r)
{
    if ( l == r ) {
        v[t] = l;
        return;
    }
    int mid = ( l + r ) >> 1;
    build( t << 1 , l , mid );
    build( t << 1 | 1 , mid + 1 , r );
    v[t] = min( v[t<<1] , v[t<<1|1] );
}

void init()
{
    int sum = 0;
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    h.clear();
    rep(i,1,n) {
        l[i] = h.count( a[i] ) ? h[a[i]] : 0; 
        h[a[i]] = i;
    }
    h.clear();
    red(i,n,1) {
        r[i] = h.count( a[i] ) ? h[a[i]] : n + 1;
        h[a[i]] = i;
    }
    build( 1 , 1 , n );
}

void dfs(int t,int l,int r)
{
    if ( v[t] > as ) return;
    if ( l >= al && r <= ar ) {
        v[t] = as;
        return;
    }
    v[t<<1] = max( v[t<<1] , v[t] );
    v[t<<1|1] = max( v[t<<1|1] , v[t] );
    int mid = ( l + r ) >> 1;
    if ( al <= mid ) dfs( t << 1 , l , mid );
    if ( ar > mid ) dfs( t << 1 | 1 , mid + 1 , r );
    v[t] = min( v[t<<1] , v[t<<1|1] );
}

void work()
{
    rep(i,1,n) {
        al = l[i] + 1 , ar = i , as = r[i] - 1;
        dfs( 1 , 1 , n );
        if ( v[1] < i ) {
            puts("boring");
            return;
        }
    }
    puts("non-boring");
}

int main()
{
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
