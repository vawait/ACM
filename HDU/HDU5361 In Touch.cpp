/*
 * Author:  vawait
 * Created Time:  2015/8/6 12:15:14
 * Problem: HDU5361 In Touch
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
#define ls ( t << 1 )
#define rs ( t << 1 | 1 )
typedef long long lint;
typedef pair < lint , int > pp;
const int maxn = 401000;
const lint mm = 1e16;
int n , L[maxn] , R[maxn] , C[maxn];
lint ans[maxn];
char c;

void scan(int &x){
    while(c=getchar(),c<'0'||c>'9');x=c-'0';
    while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';
}

struct nodd
{
    lint v[maxn<<3] ;
    bool flag[maxn<<3];
    pp a[maxn<<3];
    lint al , ar , as;
    void up(int t) {
        a[t] = min( a[ls] , a[rs] );
        flag[t] = flag[ls] & flag[rs];
    }
    void build(int t,int l,int r) {
        flag[t] = 0;
        v[t] = mm;
        if ( l == r ) {
            a[ls].y = a[rs].y = l;
            a[t] = mp( l == 1 ? 0 : mm , l );
            return;
        }
        int mid = ( l + r ) >> 1;
        build( ls , l , mid );
        build( rs , mid + 1 , r );
        up( t );
    }
    void down(int t) {
        if ( !flag[ls] && v[ls] > v[t] ) {
            v[ls] = v[t];
            if ( v[t] < a[ls].x ) {
                a[ls].x = v[t];
                a[ls].y = min( a[ls<<1].y , a[ls<<1|1].y );
            }
        }
        if ( !flag[rs] && v[rs] > v[t] ) {
            v[rs] = v[t];
            if ( v[t] < a[rs].x ) {
                a[rs].x = v[t];
                a[rs].y = min( a[rs<<1].y , a[rs<<1|1].y );
            }
        }
    }
    void cha(int t,int l,int r,int x) {
        if ( l == r ) {
            flag[t] = 1;
            a[t].x = mm;
            a[t].y = 1e9;
            return;
        }
        down( t );
        int mid = ( l + r ) >> 1;
        if ( x <= mid ) cha( ls , l , mid , x ); else cha( rs , mid + 1 , r , x );
        up( t );
    }
    void cha(int t,int l,int r) {
        if ( flag[t] ) return;
        if ( al <= l && r <= ar ) {
            v[t] = min( v[t] , as );
            if ( v[t] < a[t].x ) {
                a[t].x = v[t];
                a[t].y = min( a[ls].y , a[rs].y );
            }
            return;
        }
        down( t );
        int mid = ( l + r ) >> 1;
        if ( al <= mid ) cha( ls , l , mid ); 
        if ( ar > mid ) cha( rs , mid + 1 , r );
        up( t );
    }
} T;

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scan(L[i]) , ans[i] = -1;
    rep(i,1,n) scan(R[i]);
    rep(i,1,n) scan(C[i]);
    T.build( 1 , 1 , n );
} 

void work()
{
    int x , l , r;
    rep(i,1,n) {
        if ( T.a[1].x >= mm ) break;
        x = T.a[1].y;
        ans[x] = T.a[1].x;
        T.cha( 1 , 1 , n , x );
        T.as = ans[x] + C[x];
        if ( x - L[x] > 0 ) {
            T.al = max( 1 , x - R[x] );
            T.ar = x - L[x];
            T.cha( 1 , 1 , n );
        }
        if ( x + L[x] <= n ) {
            T.al = x + L[x];
            T.ar = min( n , x + R[x] );
            T.cha( 1 , 1 , n );
        }
    }
    rep(i,1,n) printf("%I64d%c",ans[i],i==n?'\n':' ');
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
