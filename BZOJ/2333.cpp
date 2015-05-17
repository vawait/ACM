/*
 * Author:  vawait
 * Created Time:  2015/5/17 14:27:48
 * Problem: BZOJ_2333
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
int n , m , sum , A[maxn] , q[maxn] , f[maxn] , L[maxn] , R[maxn];
int num[maxn] , vis[maxn] , op1[maxn] , op2[maxn];
int last[maxn] , next[maxn];
char op[maxn][5];

struct nodd
{
    lint v[maxn<<3] , a[maxn<<3];
    lint al , ar , as;
    void build(int t,int l,int r) {
        v[t] = 0;
        if ( l == r ) {
            a[t] = A[q[l]];
            return;
        }
        int mid = ( l + r ) >> 1;
        build( ls , l , mid );
        build( rs , mid + 1 , r );
        a[t] = max( a[ls] , a[rs] );
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
        a[t] = max( a[ls] , a[rs] );
    }
    lint ask(int t,int l,int r) {
        if ( al <= l && r <= ar )
            return a[t];
        int mid = ( l + r ) >> 1;
        lint ans = -1e15;
        if ( v[t] ) down( t );
        if ( al <= mid ) ans = max( ans , ask( ls , l , mid ) );
        if ( ar > mid ) ans = max( ans , ask( rs , mid + 1 , r ) );
        return ans;
    }
} T;

int find(int t)
{
    return f[t] == t ? t : f[t] = find( f[t] );
}

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&A[i]);
    scanf("%d",&m);
    rep(i,1,m) {
        scanf("%s",op[i]);
        if ( op[i][0] == 'F' ) {
            if ( op[i][1] != '3' ) scanf("%d",&op1[i]);
        } else {
            if ( op[i][1] == '3' ) scanf("%d",&op1[i]);
            else scanf("%d%d",&op1[i],&op2[i]);
        }
    }
    rep(i,1,n) f[i] = i , last[i] = i;
    rep(i,1,m) if ( op[i][0] == 'U' ) {
        int x = find( op1[i] ) , y = find( op2[i] );
        if ( x == y ) continue;
        next[last[x]] = y;
        last[x] = last[y];
        vis[y] = 1;
        f[y] = x;
    }
    sum = 0;
    rep(i,1,n) {
        f[i] = i;
        if ( !vis[i] ) {
            for ( int j = i; j; j = next[j] ) {
                q[++sum] = j;
                num[j] = L[j] = R[j] = sum;
            }
        }
    }
    T.build( 1 , 1 , n );
}

void work()
{
    rep(i,1,m) {
        if ( op[i][0] == 'U' ) {
            int x = find( op1[i] ) , y = find( op2[i] );
            if ( x == y ) continue;
            L[x] = min( L[x] , L[y] );
            R[x] = max( R[x] , R[y] );
            f[y] = x;
        }
        if ( op[i][0] == 'A' ) {
            if ( op[i][1] == '3' ) {
                T.al = 1 , T.ar = n , T.as = op1[i];
            } else {
                T.as = op2[i];
                if ( op[i][1] == '1' ) {
                    T.al = T.ar = num[op1[i]];
                } else {
                    int x = find( op1[i] );
                    T.al = L[x] , T.ar = R[x];
                }
            }
            T.cha( 1 , 1 , n );
        }
        if ( op[i][0] == 'F' ) {
            if ( op[i][1] == '1' )
                T.al = T.ar = num[op1[i]];
            if ( op[i][1] == '2' ) {
                int x = find( op1[i] );
                T.al = L[x] , T.ar = R[x];
            }
            if ( op[i][1] == '3' )
                T.al = 1 , T.ar = n;
            printf("%d\n",(int)T.ask(1,1,n));
        }
    }
}

int main()
{
    init();
    work();
    return 0;
}
