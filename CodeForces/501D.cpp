/*
 * Author:  vawait
 * Created Time:  2015/1/12 17:32:17
 * Problem: CodeForces_501D
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
int n , a[maxn] , b[maxn];
lint f[maxn];

struct bit
{
    int t[maxn+10];
    void add(int x,int y) {
        for ( ; x <= maxn; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
    void cl() {
        clr( t , 0 );
    }
} T;

void deal(int *a)
{
    int x;
    T.cl();
    red(i,n,1) {
        x = a[i];
        if ( x ) f[n-i] += T.sum( x );
        T.add( x + 1 , 1 );
    }
}

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) scanf("%d",&b[i]);
    clr( f , 0 );
    deal( a );
    deal( b );
    rep(i,1,n-1) {
        f[i+1] += f[i] / ( i + 1 );
        f[i] %= i + 1;
    }
}

void work()
{
    int x;
    T.cl();
    rep(i,1,n) T.add( i , 1 );
    rep(i,1,n) {
        int x = f[n-i] , l = 1 , r = n , k;
        while ( l < r ) {
            k = ( l + r ) >> 1;
            if ( T.sum( k ) > x ) r = k; else l = k + 1;
        }
        T.add( l , -1 );
        a[i] = l - 1;
    }
    rep(i,1,n-1) printf("%d ",a[i]);
    printf("%d\n",a[n]);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
