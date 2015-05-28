/*
 * Author:  vawait
 * Created Time:  2015/5/28 14:41:02
 * Problem: UVALive6838 FlippingParentheses
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
const int maxn = 301000;
int n , m , sum[maxn];
char a[maxn];
priority_queue < int > q;

struct nodd
{
    int v[maxn<<3] , a[maxn<<3];
    int al , ar , as;
    void build(int t,int l,int r) {
        v[t] = 0;
        if ( l == r ) {
            a[t] = sum[l];
            return;
        }
        int mid = ( l + r ) >> 1;
        build( ls , l , mid );
        build( rs , mid + 1 , r );
        a[t] = min( a[ls] , a[rs] );
    }
    void down(int t) {
        v[ls] += v[t]; v[rs] += v[t];
        a[ls] += v[t]; a[rs] += v[t];
        v[t] = 0;
    }
    void cha(int t,int l,int r) {
        if ( al <= l && r <= ar ) {
            a[t] += as;
            v[t] += as;
            return;
        }
        if ( v[t] ) down( t );
        int mid = ( l + r ) >> 1;
        if ( al <= mid ) cha( ls , l , mid );
        if ( ar > mid ) cha( rs , mid + 1 , r );
        a[t] = min( a[ls] , a[rs] );
    }
    int ask(int t,int l,int r) {
        if ( al <= l && r <= ar )
            return a[t];
        int mid = ( l + r ) >> 1;
        int ans = 1e9;
        if ( v[t] ) down( t );
        if ( al <= mid ) ans = min( ans , ask( ls , l , mid ) );
        if ( ar > mid ) ans = min( ans , ask( rs , mid + 1 , r ) );
        return ans;
    }
} T;

void init()
{
    scanf("%s",a+1);
    while ( !q.empty() ) q.pop();
    rep(i,1,n) {
        sum[i] = a[i] == '(' ? sum[i-1] + 1 : sum[i-1] - 1;
        if ( a[i] == ')' ) q.push( -i );
    }
    T.build( 1 , 1 , n );
}

void work()
{
    int x;
    while ( m -- ) {
        scanf("%d",&x);
        if ( a[x] == '(' ) {
            q.push( -x );
            a[x] = ')';
            T.al = x , T.ar = n , T.as = -2;
            T.cha( 1 , 1 , n );
            while ( 1 ) {
                x = -q.top(); q.pop();
                if ( a[x] == ')' ) break;
            }
            a[x] = '(';
            T.al = x , T.ar = n , T.as = 2;
            T.cha( 1 , 1 , n );
            printf("%d\n",x);
        } else {
            int l = 1 , r = x , mid;
            a[x] = '(';
            T.al = x , T.ar = n , T.as = 2;
            T.cha( 1 , 1 , n );
            while ( l < r ) {
                mid = ( l + r ) >> 1;
                T.al = mid , T.ar = x;
                if ( T.ask( 1 , 1 , n ) >= 2 ) r = mid; else l = mid + 1;
            }
            printf("%d\n",l);
            a[l] = ')';
            q.push( -l );
            T.al = l , T.ar = n , T.as = -2;
            T.cha( 1 , 1 , n );
        }
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
