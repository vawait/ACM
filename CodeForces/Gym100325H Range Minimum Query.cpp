/*
 * Author:  vawait
 * Created Time:  2015/9/4 13:34:21
 * Problem: Gym100325H Range Minimum Query
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
const int m = 1 << 18;
int n , a[maxn] , b[maxn];
char ty[maxn][2];

struct zkw
{
    int mx[1000000] , size[1000000];
    void cha(int l,lint k,int f) {
        l += m;
        size[l] += f; mx[l] = k;
        for ( int i = l >> 1; i; i >>= 1 ) {
            size[i] = size[i<<1] + size[i<<1|1];
            mx[i] = min( mx[i<<1] , mx[i<<1|1] ); 
        }
    }
    int find(int k)
    {
        int t = 1 , l = 1 , r = m;
        while ( l != r ) {
            if ( size[t<<1] >= k ) {
                r = ( l + r ) >> 1;
                t <<= 1;
            } else {
                k -= size[t<<1];
                t = t << 1 | 1;
                l = ( l + r ) / 2 + 1;
            }
        }
        return t;
    }
    int ask(int l,int r) {
        int ans = 2e9;
        l = find( l ) - 1 , r = find( r ) + 1;
        for ( ; l^r^1; l>>=1 , r>>=1 ) {
            if ( ~l&1 ) ans = min( ans , mx[l^1] );
            if ( r&1 ) ans = min( ans , mx[r^1] );
        }
        return ans;
    }
} T , T1;

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%s%d%d",ty[i],&a[i],&b[i]);
    rep(i,1,m+m) T.mx[i] = 2e9;
    rep(i,m+1,m+m) T1.size[i] = 1;
    red(i,m-1,1) T1.size[i] = T1.size[i<<1] + T1.size[i<<1|1];
    red(i,n,1) if ( ty[i][0] == '+' ) {
        a[i] = T1.find( a[i] + 1 ) - m;
        T1.cha( a[i] , 0 , -1 );
    }
}

void work()
{
    rep(i,1,n) if ( ty[i][0] == '+' ) {
        T.cha( a[i] , b[i] , 1 );
    } else {
        printf("%d\n",(int)T.ask(a[i],b[i]));
    }
}

int main()
{
    freopen("rmq.in","r",stdin);
    freopen("rmq.out","w",stdout);
    init();
    work();
    return 0;
}
