/*
 * Author:  vawait
 * Created Time:  2015/10/7 16:20:02
 * Problem: Aizu2449 Connect
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
#define two( x ) ( 1 << ( x - 1 ) )
typedef long long lint;
int n , m , len[200] , f[2][1<<16] , now = 1 , nex = 0 , ltwo[20] , rtwo[20] , d[1<<17];
char a[200][20];

void init()
{
    cin >> n >> m;
    rep(i,1,n) {
        scanf("%s",a[i]+1);
        len[i] = strlen( a[i] + 1 );
    }
    d[0] = rtwo[18] = ltwo[0] = 0;
    red(i,17,1) rtwo[i] = rtwo[i+1] | two( i );
    rep(i,1,17) ltwo[i] = ltwo[i-1] | two( i );
    rep(i,1,(1<<16)) d[i] = d[i>>1] + ( i & 1 );
    clr( f[now] , 240 );
    f[now][0] = 0;
}

void work()
{
    int ans = 0 , x , y , z;
    rep(i,1,n) {
        rep(j,1,m) {
            clr( f[nex] , 240 );
            red(k,(1<<m)-1,0) if ( f[now][k] >= 0 ) {
                x = k;
                if ( two( j ) & x ) x ^= two( j );
                f[nex][x] = max( f[nex][x] , f[now][k] );
                if ( ( z = d[ k & ltwo[j-1] ] ) < len[i] ) {
                    y = f[now][k];
                    x |= two( j );
                    if ( z && ( two( j - 1 ) & k ) && a[i][z] == a[i][z+1] ) y += 2;
                    if ( i > 1 && ( two( j ) & k ) && a[i][z+1] == a[i-1][len[i-1]+1-d[k&rtwo[j]]] ) y += 2;
                    f[nex][x] = max( f[nex][x] , y );
                }
            }
            swap( now , nex );
        }
        x = -1e9;
        rep(j,0,(1<<m)-1) if ( d[j] != len[i] ) f[now][j] = x;
    }
    rep(i,0,(1<<m)-1) ans = max( ans , f[now][i] );
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
