/*
 * Author:  vawait
 * Created Time:  2015/9/1 13:28:15
 * Problem: Gym100340E Minima
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
int n , a[310][310] , ans[310] , vis[310] , t[101000][302] , f[101000] , can[310];
int now = 1 , sum = 0;

void init()
{
    scanf("%d",&n);
    rep(i,1,n)
        rep(j,1,n-1) scanf("%d",&a[i][j]);
    rep(i,1,n) {
        int x , p = 0;
        rep(j,1,n-1) {
            x = a[i][j];
            if ( !t[p][x] ) {
                t[p][x] = ++sum;
            }
            p = t[p][x];
        }
    }
}

bool ok(int x,int y)
{
    ans[1] = x;
    rep(i,2,n) {
        ans[i] = a[y][i-1];
        if ( ans[i] >= x ) ans[i] ++;
    }
    clr( vis , 0 );
    rep(i,1,n) vis[ans[i]] ++;
    rep(i,1,n) if ( !vis[i] ) return 0;
    now ++;
    rep(i,1,n) {
        int p = 0 , y = ans[i] , x;
        rep(j,1,n) if ( i != j ) {
            x = ans[j];
            if ( x >= y ) x --;
            if ( !t[p][x] ) return 0;
            p = t[p][x];
            f[p] = now;
        }
    }
    rep(i,1,sum) if ( f[i] != now ) return 0;
    rep(i,1,n) printf("%d ",ans[i]);
    return 1;
}

void work()
{
    rep(i,1,n) can[a[i][1]] = can[a[i][1]+1] = 1;
    rep(i,1,n)
        rep(j,1,n) if ( can[j] && ok( j , i ) ) return;
}

int main()
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    init();
    work();
    return 0;
}
