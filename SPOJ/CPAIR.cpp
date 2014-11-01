/*
 * Author:  vawait
 * Created Time:  2014/11/1 23:33:19
 * Problem: SPOJ_CPAIR
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
int n , m , f[maxn] , sum[maxn] , l[maxn] , r[maxn];
lint ans[maxn];
vector < int > num[1100] , q[1100];

struct nodd
{
    int vsum , v , l , r , m;
    lint sum , slen , len;
} T[maxn*4];

void build(int t,int l,int r)
{
    T[t].l = l; T[t].r = r;
    T[t].m = ( l + r ) >> 1;
    T[t].len = r - l + 1;
    T[t].slen = ( l + r ) * T[t].len / 2;
    if ( l == r ) return;
    build( t << 1 , l , T[t].m );
    build( t + t + 1 , T[t].m + 1 , r );
}

int find(int t)
{
    return f[t] == t ? t : find( f[t] );
}

void init()
{
    int v;
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&v) , num[v].pb( i );
    rep(i,1,n) f[i] = i;
    rep(i,1,m) scanf("%d%d%d",&v,&l[i],&r[i]) , q[v].pb( i );
    build( 1 , 1 , n );
}

void calc(int t,int vsum,int v)
{
    T[t].vsum += vsum;
    T[t].v += v;
    T[t].sum += vsum * T[t].len - v * T[t].slen;
}

void down(int t)
{
    calc( t << 1 , T[t].vsum , T[t].v );
    calc( t + t + 1 , T[t].vsum , T[t].v );
    T[t].vsum = T[t].v = 0;
}

void add(int t,int r,int vsum,int v)
{
    if ( T[t].r <= r ) {
        calc( t , vsum , v ); 
        return ;
    }
    if ( T[t].vsum || T[t].v ) down( t );
    add( t << 1 , r , vsum , v );
    if ( r > T[t].m ) add( t + t + 1 , r , vsum , v );
    T[t].sum = T[t<<1].sum + T[t+t+1].sum;
}

lint ask(int t,int l,int r)
{
    lint sum = 0;
    if ( T[t].l >= l && T[t].r <= r ) return T[t].sum;
    if ( T[t].vsum || T[t].v ) down( t );
    if ( T[t].m >= l ) sum += ask( t << 1 , l , r );
    if ( T[t].m < r ) sum += ask( t + t + 1 , l , r );
    return sum;
}

void link(int x,int y)
{
    x = find( x ); y = find( y );
    f[y] = x;
    sum[x] += sum[y];
    add( 1 , sum[y] , -( sum[y] + 1 ) , -1 );
}

void work()
{
    int x , p;
    red(v,1000,0) {
        red(i,num[v].size()-1,0) {
            x = num[v][i];
            sum[x] = 1;
            if ( x > 1 && sum[x-1] ) link( x , x - 1 );
            if ( x < n && sum[x+1] ) link( x , x + 1 );
            x = sum[find( x )];
            add( 1 , x , x + 1 , 1 );
        }
        red(i,q[v].size()-1,0) {
            x = q[v][i];
            ans[x] = ask( 1 , l[x] , r[x] );
        }
    }
    rep(i,1,m) printf("%lld\n",ans[i]);
}

int main()
{
    init();
    work();
    return 0;
}
