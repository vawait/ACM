/*
 * Author:  vawait
 * Created Time:  2015/7/28 14:27:43
 * Problem: HDU5323 Solve this interesting problem
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
lint l , r , n;

void init()
{
    n = 1e15;
}

void dfs(lint l,lint r)
{
    if ( l < 0 || r >= n ) return;
    if ( l == 0 ) {
        n = min( n , r );
        return;
    }
    if ( r - l > l ) return;
    lint s = r - l + 1 , x = l - s - 1 , y = r;
    if ( x >= 0 && ( ( x + y ) >> 1 ) ==  l - 1 )
        dfs( x , y ); 
    x ++;
    if ( x >= 0 && ( ( x + y ) >> 1 ) ==  l - 1 )
        dfs( x , y );
    x = l , y = r + s - 1;
    if ( y < n && ( ( x + y ) >> 1 ) ==  r )
        dfs( x , y );
    y ++;
    if ( y < n && ( ( x + y ) >> 1 ) ==  r )
        dfs( x , y );
}

void work()
{
    dfs( l , r );
    if ( n > 1e14 ) n = -1;
    cout << n << endl;
}

int main()
{
    while ( cin >> l >> r ) {
        init();
        work();
    }
    return 0;
}
