/*
 * Author:  vawait
 * Created Time:  2014/10/30 19:05:53
 * File Name: CodeChef_SEABAL.cpp
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
const int maxn = 100000;
int n , m , a[maxn+10] , pre[maxn+10] , nex[maxn+10];
int root[maxn];
pair < int , int > q[maxn+10];

struct ZXTree
{
    struct node {
        int l , r , v , m;
    } T[maxn*310];
    int sz;
    void build(int &i,int l ,int r) {
        i = ++sz;
        T[i].l = T[i].r = T[i].v = 0;
        T[i].m = ( l + r ) >> 1;
        if ( l < r ) build( T[i].l , l , T[i].m ) , build( T[i].r , T[i].m + 1 , r );
    }
    void ins(int &i,int l,int r,int x) {
        T[++sz] = T[i]; i = sz;
        T[i].v ++;
        if ( l == r ) return;
        if ( x <= T[i].m ) ins( T[i].l , l , T[i].m , x ); else ins ( T[i].r , T[i].m + 1 , r , x );
    }
    int ask(int x,int L,int R,int l,int r) {
        if ( l <= L && r >= R ) return T[x].v;
        int s = 0;
        if ( l <= T[x].m ) s += ask( T[x].l , L , T[x].m , l , r );
        if ( r > T[x].m ) s += ask( T[x].r , T[x].m + 1 , R , l , r );
        return s;
    }
    void init() {
        root[0] = sz = 0;
        build( root[0] , 1 , n );
    }
} T;

void init()
{
    int l , r;
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,m) scanf("%d%d",&q[i].y,&q[i].x);
    rep(i,0,n+5) nex[i] = i + 1; 
    rep(i,0,n+5) pre[i] = i - 1; 
    T.init();
    int x = 1;
    sort( q + 1 , q + 1 + m );
    rep(i,1,n) {
        root[i] = root[i-1];
        while ( x <= m && q[x].x == i ) T.ins( root[i] , 1 , n , q[x++].y );
    }
}

void work()
{
    int q , x , l , r , ans = 0;
    scanf("%d",&q);
    while ( q -- ) {
        scanf("%d",&x);
        x += ans;
        if ( ( -- a[x] ) == 0 ) {
            l = pre[x] , r = nex[x];
            nex[l] = r; pre[r] = l;
            ans += T.ask( root[r-1] , 1 , n , l + 1 , x ) - T.ask( root[x-1] , 1 , n , l + 1 , x );
        }
        printf("%d\n",ans);
    }
}

int main()
{
    init();
    work();
    return 0;
}
