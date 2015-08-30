/*
 * Author:  vawait
 * Created Time:  2015/8/29 13:44:16
 * Problem: Gym100345D Currency Exchange
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
#define repp(i, a, b) for ( c[i] = (a); c[i] <= (b); ++c[i])
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x) * (x))
typedef long long lint;
lint m , l , r , a[30] , b[30] , c[100];
lint f[21][60000];

int num()
{
    rep(i,0,9) if ( c[i] > 2 || c[i] < 0 ) return -1;
    int n = 0;
    red(i,9,0) n = n * 3 + c[i];
    return n;
}

int calc(int n,int k)
{
    rep(i,0,9) c[i] = n % 3 , n /= 3;
    c[k] ++;
    return num();
}

void init()
{
    m = 0;
    rep(i,1,10) m = m * 3 + 2;
    
    int x;
    f[0][0] = 1;
    rep(i,0,18)
        rep(j,0,m) if ( f[i][j] ) {
            rep(k,0,9) {
                x = calc( j , k );
                if ( x > 0 ) f[i+1][x] += f[i][j] ;
            }
        }
    rep(i,0,19)
        rep(k,0,9) {
            rep(j,0,m) if ( f[i][j] ) {
                x = calc( j , k  );
                if ( x > 0 ) f[i][x] += f[i][j];
            }
        }
}

lint ans(lint n)
{
    lint sum = 1 , zero = 1 , pre = 1;
    clr( c , 0 );
    clr( a , 0 );
    rep(i,1,20) if ( n ) a[i] = n % 10 , c[a[i]] ++ , n /= 10;
    rep(i,0,9) if ( c[i] > 2 ) sum = 0;
    
    rep(i,0,9) c[i] = 2;
    int top = 20;
    while ( top > 1 && !a[top] ) top --;
    if ( a[top] ) {
        if ( top > 1 ) sum ++;
        red(i,top-1,1)
            rep(j,1,9) {
                c[j] --;
                sum += f[i-1][num()];
                c[j] ++;
            }
    }
    red(i,top,1) {
        int x = a[i];
        if ( i == 1 ) zero = 0;
        rep(j,0+zero,x-1) {
            c[j] --;
            sum += f[i-1][num()];
            c[j] ++;
        }
        c[x] --;
        zero = 0;
    }
    return sum;
}

void work()
{
    lint l , r;
    cin >> l >> r;
    cout << ans( r ) - ans( l - 1 ) << endl;
}

int main()
{
    //freopen("exchange.in","r",stdin);
    //freopen("exchange.out","w",stdout);
    init();
    work();
    return 0;
}
