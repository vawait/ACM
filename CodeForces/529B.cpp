/*
 * Author:  vawait
 * Created Time:  2015/3/22 16:38:09
 * Problem: CodeForces_529B
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
int n , ans , w[1100] , h[1100];

void init()
{
    rep(i,1,n) scanf("%d%d",&w[i],&h[i]);
    ans = 1e9;
}

void deal(int k)
{
    int sum = 0 , m = n / 2;
    priority_queue < int > q;
    rep(i,1,n) {
        if ( h[i] > k ) {
            if ( w[i] > k || ( m -- ) < 1 ) return;
            sum += h[i];
        } else {
            sum += w[i];
            if ( w[i] <= k ) q.push( w[i] - h[i] );
        }
    }
    while ( m && !q.empty() ) {
        int y = q.top(); q.pop();
        if ( y < 0 ) break;
        m --; sum -= y;
    }
    ans = min( ans , sum * k );
}

void work()
{
    rep(i,1,n) deal( w[i] ) , deal( h[i] );
    cout << ans << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
