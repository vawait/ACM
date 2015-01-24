/*
 * Author:  vawait
 * Created Time:  2015/1/24 0:18:18
 * Problem: CodeForces_507C
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
lint n , m , f[60] , ans;

void init()
{
    f[0] = 1;
    rep(i,1,n) f[i] = f[i-1] + ( 1LL << i );
    m += ( 1LL << n ) - 1;
    ans = 0;
}

bool find(lint num)
{
    lint mm = m;
    while ( mm ) {
        if ( mm == num ) return 1;
        mm >>= 1;
    }
    return 0;
}

bool dfs(lint num,lint h,int v)
{
    if ( num == m ) return 1;
    //cout << num << " " << h << " "<< v << endl;
    if ( !find( num ) ) {
        ans += f[n-h];
        return 0;
    }
    ans ++;
    if ( !v ) {
        if ( !dfs( num << 1 , h + 1 , 1 ) ) dfs( num << 1 | 1 , h + 1 , 0 );
    } else {
        if ( !dfs( num << 1 | 1 , h + 1 , 0 ) ) dfs( num << 1 , h + 1 , 1 );
    }
    return 1;
}

void work()
{
    dfs( 1 , 0 , 0 );
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
