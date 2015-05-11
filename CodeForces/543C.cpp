/*
 * Author:  vawait
 * Created Time:  2015/5/11 14:52:31
 * Problem: CodeForces_543C
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
int n , m , mm , f[1<<20] , a[30][30];
char c[30][30];

void mx(int &x,int y)
{
    if ( y < x ) x = y;
}

void init()
{
    mm = ( 1 << n ) - 1;
    rep(i,1,mm) f[i] = 1e9;
    rep(i,1,n) scanf("%s",c[i]+1);
    rep(i,1,n) {
        int x = 1e9;
        rep(j,1,m) scanf("%d",&a[i][j]) , mx( x , a[i][j] );
        rep(j,0,mm) mx( f[j|two(i)] , f[j] + x );
    }
}

void work()
{
    rep(j,1,m) {
        rep(i,1,n) {
            vector < int > g;
            int sum = 0 , v = 0;
            rep(k,1,n) if ( c[i][j] == c[k][j] ) 
                v |= two( k ) , g.pb( k );
            if ( g[0] != i ) continue;
            red(k,g.size()-1,0) g[k] = a[g[k]][j];
            sort( g.begin() , g.end() );
            red(k,g.size()-2,0) sum += g[k];
            rep(k,0,mm) mx( f[k|v] , f[k] + sum );
        }
    }
    cout << f[mm] << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
