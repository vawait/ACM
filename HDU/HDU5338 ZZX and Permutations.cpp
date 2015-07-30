/*
 * Author:  vawait
 * Created Time:  2015/7/30 16:54:41
 * Problem: HDU5338 ZZX and Permutations
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
#define ls ( t << 1 )
#define rs ( t << 1 | 1 )
#define sqr(x) ((x) * (x))
typedef long long lint;
const int maxn = 101000;
int n , A[maxn] , ans[maxn] , p[maxn] , use[maxn];

struct nodd
{
    int a[maxn<<2];
    void build(int t,int l,int r) {
        if ( l == r ) {
            a[t] = A[l];
            return;
        }
        int mid = ( l + r ) >> 1;
        build( ls , l , mid );
        build( rs , mid + 1 , r );
        a[t] = max( a[ls] , a[rs] );
    }
    void cha(int t,int l,int r,int x) {
        if ( l == r ) {
            a[t] = 0;
            return;
        }
        int mid = ( l + r ) >> 1;
        if ( x <= mid ) cha( ls , l , mid , x );
        if ( x > mid ) cha( rs , mid + 1 , r , x );
        a[t] = max( a[ls] , a[rs] );
    }
    int ask(int t,int l,int r,int al,int ar) {
        if ( al <= l && r <= ar )
            return a[t];
        int mid = ( l + r ) >> 1;
        int ans = 0;
        if ( al <= mid ) ans = max( ans , ask( ls , l , mid , al , ar ) );
        if ( ar > mid ) ans = max( ans , ask( rs , mid + 1 , r , al , ar ) );
        return ans;
    }
} T;


void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&A[i]) , p[A[i]] = i;
    rep(i,1,n) use[i] = 0;
    T.build( 1 , 1 , n );
}

void work()
{
    set < int > h;
    set < int > ::iterator it;
    h.insert( 0 );
    h.insert( n + 1 );
    rep(i,1,n) if ( !use[i] ) {
        int x = p[i] , l;
        h.insert( x );
        it = --h.find( x );
        l = *it + 1;
        int y = T.ask( 1 , 1 , n , l , x );
        it ++; it ++;
        h.erase( x );
        if ( x == *it - 1 || y > A[x+1] ) {
            rep(j,p[y],x) {
                T.cha( 1 , 1 , n , j );
                ans[A[j]] = A[j+1];
                use[A[j]] = 1;
            }
            ans[A[x]] = A[p[y]];
            h.insert( p[y] );
            h.insert( x );
        } else {
            T.cha( 1 , 1 , n , x + 1 );
        }
    }
    rep(i,1,n) printf("%d%c",ans[i],i==n?'\n':' ');
}

int main()
{
    int t;
    for ( cin >> t; t; t -- ) {
        init();
        work();
    }
    return 0;
}
