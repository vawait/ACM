/*
 * Author:  vawait
 * Created Time:  2015/10/6 13:54:45
 * Problem: SCU4445 Right turn
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
const int maxn = 1010;
int n , m , num , x[maxn] , y[maxn];
bool vis[maxn][maxn][4] , ob[maxn][maxn];
int dx[] = { 1 , 0 , -1 , 0 };
int dy[] = { 0 , -1 , 0 , 1 };
vector < int > g;

void init()
{
    rep(i,1,num) scanf("%d%d",&x[i],&y[i]);
    x[0] = y[0] = 0;
    
    g.clear();
    rep(i,0,num) g.pb( x[i] );
    sort( g.begin() , g.end() );
    g.resize( unique( g.begin() , g.end() ) - g.begin() );
    rep(i,0,num) x[i] = lower_bound( g.begin() , g.end() , x[i] ) - g.begin() + 1;
    n = g.size();
    
    g.clear();
    rep(i,0,num) g.pb( y[i] );
    sort( g.begin() , g.end() );
    g.resize( unique( g.begin() , g.end() ) - g.begin() );
    rep(i,0,num) y[i] = lower_bound( g.begin() , g.end() , y[i] ) - g.begin() + 1;
    m = g.size();
    
    clr( vis , 0 ); clr( ob , 0 );
    rep(i,1,num) ob[x[i]][y[i]] = 1;
}

void work()
{
    int ans = 0 , i = x[0] , j = y[0] , d = 0 , xx , yy;
    while ( 1 ) {
        if ( vis[i][j][d] ) {
            puts("-1");
            return;
        }
        vis[i][j][d] = 1;
        xx = dx[d] + i , yy = dy[d] + j;
        if ( xx < 1 || xx > n || yy < 1 || yy > m ) break;
        if ( ob[xx][yy] ) {
            ( d += 1 ) %= 4;
            ans ++;
        } else {
            i = xx; j = yy;
        }
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> num ) {
        init();
        work();
    }
    return 0;
}
