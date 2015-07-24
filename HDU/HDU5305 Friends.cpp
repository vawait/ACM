/*
 * Author:  vawait
 * Created Time:  2015/7/23 12:54:22
 * Problem: HDU5305 Friends
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
int n , m , x[100] , y[100] , a[9] , b[9];
int f[4][4][4][4][4][4][4][4];

void init()
{
    clr( b , 0 );
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        scanf("%d%d",&x[i],&y[i]);
        b[x[i]] ++; b[y[i]] ++;
    }
    clr( f , 0 );
}

void work()
{
    int p = ( 1 << ( m / 2 ) ) - 1;
    rep(i,1,n) if ( b[i] & 1 ) {
        puts("0");
        return;
    } else b[i] >>= 1;
    
    rep(i,0,p) {
        clr( a , 0 );
        red(j,m/2-1,0) if ( ( i >> j ) & 1 ) {
            a[x[j+1]] ++; a[y[j+1]] ++;
        }
        int v = 1;
        rep(j,1,n) if ( a[j] > b[j] ) v = 0;
        if ( v ) {
            f[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]] ++;
        }
    }
    
    lint ans = 0;
    int mm = m / 2 + 1;
    
    rep(i,0,p) {
        rep(j,1,8) a[j] = b[j];
        red(j,m/2-1,0) if ( ( i >> j ) & 1 ) {
            a[x[j+mm]] --; a[y[j+mm]] --;
        }
        int v = 1;
        rep(j,1,n) if ( a[j] < 0 ) v = 0;
        if ( v ) {
            ans += f[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]];
        }
    }
    cout << ans << endl;
    
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
