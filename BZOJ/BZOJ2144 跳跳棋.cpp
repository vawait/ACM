/*
 * Author:  vawait
 * Created Time:  2015/10/27 15:31:21
 * Problem: BZOJ2144 跳跳棋
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
int A[10] , B[10] , C[10] , D[10];

void init()
{
    rep(i,1,3) scanf("%d",&A[i]);
    rep(i,1,3) scanf("%d",&B[i]);
    sort( A + 1 , A + 4 );
    sort( B + 1 , B + 4 );
}

int calc(int a,int b,int c,int p)
{
    int sum = 0;
    while ( a + c != b + b && p ) {
        int t1 = b - a , t2 = c - b , k = ( max( t1 , t2 ) - 1 ) / min( t1 , t2 );
        k = min( k , p );
        p -= k;
        sum += k;
        if ( t1 < t2 ) {
            a += k * t1;
            b += k * t1;
        } else {
            c -= k * t2;
            b -= k * t2;
        }
        if ( !p ) break;
    }
    C[1] = a , C[2] = b , C[3] = c;
    return sum;
}

int ok(int *a,int *b)
{
    rep(i,1,3) if ( a[i] != b[i] ) return 0;
    return 1;
}

void work()
{
    int dep1 = calc( A[1] , A[2] , A[3] , 1e9 ) , dep2;
    rep(i,1,3) D[i] = C[i];
    dep2 = calc( B[1] , B[2] , B[3] , 1e9 );
    if ( !ok( C , D ) ) {
        puts("NO");
        return;
    }
    puts("YES");
    if ( dep1 > dep2 ) {
        calc( A[1] , A[2] , A[3] , dep1 - dep2 );
        rep(i,1,3) A[i] = C[i];
    } else {
        calc( B[1] , B[2] , B[3] , dep2 - dep1 );
        rep(i,1,3) B[i] = C[i];
    }
    
    int l = 0 , r = min( dep1 , dep2 ) , k;
    while ( l < r ) {
        k = ( l + r ) >> 1;
        calc( A[1] , A[2] , A[3] , k );
        rep(i,1,3) D[i] = C[i];
        calc( B[1] , B[2] , B[3] , k );
        if ( ok( C , D ) ) r = k; else l = k + 1;
    }
    printf("%d\n",2*l+abs(dep1-dep2));
}

int main()
{
    init();
    work();
    return 0;
}
