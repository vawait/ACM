/*
 * Author:  vawait
 * Created Time:  2015/3/31 14:18:54
 * Problem: CodeForces_506C
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
const int maxn = 101000;
int n , k , p , a[maxn] , h[maxn];
lint m , now[maxn] , ned[maxn];

void init()
{
    rep(i,1,n) scanf("%d%d",&h[i],&a[i]);
    rep(i,1,n) ned[i] = m * a[i];
}

int ok(lint mid)
{
    priority_queue < pair < lint , lint > > q;
    lint sum = k * m , id;
    rep(i,1,n) {
        now[i] = mid;
        if ( mid < ned[i] ) 
            q.push( mp( -( mid / a[i] + 1 ) , i ) );
    }
    rep(i,1,m*k) if ( !q.empty() ) {
        if ( ( i + k - 1 ) / k >= -q.top().x ) return 0;
        id = q.top().y; now[id] += p; 
        sum --;
        q.pop();
        if ( now[id] < ned[id] )
            q.push( mp( -( now[id] / a[id] + 1 ) , id ) );
    }
    rep(i,1,n) {
        now[i] -= ned[i];
        if ( now[i] < h[i] ) sum -= ( h[i] - now[i] + p - 1 ) / p;
        if ( sum < 0 ) return 0;
    }
    return 1;
}

void work()
{
    lint l = 0 , r = sqr( 1e9 ) , mid;
    while ( l < r ) {
        mid = ( l + r ) >> 1;
        if ( ok( mid ) ) r = mid; else l = mid + 1;
    }
    cout << l << endl;
}

int main()
{
    while ( cin >> n >> m >> k >> p ) {
        init();
        work();
    }
    return 0;
}
