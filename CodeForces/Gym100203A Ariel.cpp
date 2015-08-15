/*
 * Author:  vawait
 * Created Time:  2015/8/15 15:49:16
 * Problem: Gym100203A Ariel
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
int n , k , m , f[maxn] , num[maxn] , sc[maxn] , ans[maxn];
vector < int > g[maxn];
pair < int , int > ask[maxn];

void init()
{
    rep(i,1,n) {
        int x = 0 , t , y;
        scanf("%d%d",&sc[i],&t);
        while ( t -- ) scanf("%d",&y) , x |= ( 1 << ( y - 1 ) );
        f[i] = x;
    }
    scanf("%d",&m);
    rep(i,1,m) {
        int x = 0 , t , y;
        scanf("%d%d",&num[i],&t);
        while ( t -- ) scanf("%d",&y) , x |= ( 1 << ( y - 1 ) );
        ask[i].x = x;
        ask[i].y = i;
    }
    sort( ask + 1 , ask + m + 1 );
}

void work()
{
    int p = m , mm = ( 1 << k ) - 1 , id , x , y;
    int l , r , mid;
    red(i,mm,0) if ( p && i == ask[p].x ) {
        rep(j,0,mm) g[j].clear();
        rep(j,1,n) g[i&f[j]].pb( sc[j] );
        rep(j,0,mm) sort( g[j].begin() , g[j].end() );
        while ( p && ask[p].x == i ) {
            id = ask[p].y; x = ask[p].x & f[num[id]];
            l = 0 , r = g[x].size() - 1 ;
            y = sc[num[id]];
            while ( l < r ) {
                mid = ( l + r + 1 ) >> 1;
                if ( g[x][mid] <= y ) l = mid; else r = mid - 1;
            }
            ans[id] = int( g[x].size() ) - l;
            p --;
        }
    }
    rep(i,1,m) printf("%d\n",ans[i]);
}

int main()
{
    while ( cin >> n >> k ) {
        init();
        work();
    }
    return 0;
}
