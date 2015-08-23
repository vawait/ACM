/*
 * Author:  vawait
 * Created Time:  2015/8/23 13:17:07
 * Problem: HDU4415 Assassin’s Creed
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
int n , m , vis[maxn];
pair < int , int > ans , q[maxn];

void init()
{
    int x , y;
    scanf("%d%d",&n,&m);
    rep(i,1,n) vis[i] = 1 , scanf("%d%d",&q[i].x,&q[i].y);
    sort( q + 1 , q + n + 1 );
    int s = 0 , num = 0;
    rep(i,1,n) if ( !q[i].y && s + q[i].x <= m ) {
        num --;
        s += q[i].x;
    }
    ans = mp( num , s );
}

void work()
{
    int mx = 2e9 , p = -1 , mm = m;
    rep(i,1,n) if ( q[i].y && q[i].x < mx ) mx = q[i].x , p = i;
    if ( p > 0 && mx <= m ) {
        int num = -1 , x = 0;
        vis[p] = 0;
        m -= mx;
        rep(i,1,n) if ( vis[i] && q[i].x <= m ) {
            m -= q[i].x;
            num --;
            vis[i] = 0;
        }
        rep(i,1,n) x += q[i].y;
        red(i,n,1) if ( x && i != p ) {
            x --;
            if ( vis[i] ) {
                num --;
            } else {
                m += q[i].x;
            }
        }
        ans = min( ans , mp( num , mm - m ) );
    }
    printf("%d %d\n",-ans.x,ans.y);
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case %d: ",i);
        init();
        work();
    }
    return 0;
}
