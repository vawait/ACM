/*
 * Author:  vawait
 * Created Time:  2014/10/31 13:06:08
 * File Name: SPOJ_ TRES.cpp
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
lint a , b , f[20][10][20][2] , sum[20][10][20][2] , d[20];

void init()
{
}

lint ask(lint t)
{
    int x , vv;
    rep(i,1,20) d[i] = t % 10 , t /= 10;
    clr( f , 0 ); 
    clr( sum , 0 );
    f[18][0][0][0] = 1;
    red(i,18,1) rep(j,0,9)
        rep(k,0,19) rep(v,0,1) if ( f[i][j][k][v] ) {
            x = v ? 9 : d[i];
            red(r,x,0) {
                vv = v || ( r < d[i] );
                if ( r == j ) {
                    sum[i-1][j][k+1][vv] += sum[i][j][k][v];
                    f[i-1][j][k+1][vv] += f[i][j][k][v];
                } else {
                    sum[i-1][r][1][vv] += sum[i][j][k][v] + f[i][j][k][v] * j * sqr( k );
                    f[i-1][r][1][vv] += f[i][j][k][v];
                }
            }
        }
    
    lint ans = 0;
    rep(j,0,9) 
        rep(k,0,15)
            rep(v,0,1) ans += sum[0][j][k][v] + f[0][j][k][v] * j * sqr( k );
    return ans;
}

void work()
{
    cout << ask( b ) - ask( a - 1 ) << endl;
}

int main()
{
    while ( cin >> a >> b ) {
        init();
        work();
    }
    return 0;
}
