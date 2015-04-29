/*
 * Author:  vawait
 * Created Time:  2015/4/29 14:48:36
 * Problem: ZOJ_3871
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
const lint mm = 998244353;
const lint mm2 = 748683265;
lint ans , fn[2100];
int n;
pair < double , int > q[4100];

struct nodd
{
    int x , y;
} a[4100];

void init()
{
    fn[0] = 1;
    scanf("%d",&n);
    rep(i,1,n) fn[i] = 2 * fn[i-1] % mm;
    rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    ans = 0;
}

lint cross(int x,int y,int z)
{
    return (lint)(a[x].x - a[z].x) * ( a[y].y - a[z].y ) - (lint)( a[x].y - a[z].y ) * ( a[y].x - a[z].x );
}

void deal(int id)
{
    int s = 0 , p = 1;
    rep(i,1,n) if ( i != id )
        q[++s] = mp( atan2( a[i].y - a[id].y , a[i].x - a[id].x ) , i );
    sort( q + 1 , q + n );
    rep(i,1,n-1) q[i+n-1] = q[i];
    rep(i,1,n-1) {
        while ( p - i < n - 1 && cross( id , q[i].y , q[p].y ) >= 0 ) p ++;
        lint ss = -cross( id , q[i].y , 0 ) % mm;
        //printf("%d:%d %d %lld\n",id,i,p,ss);
        ( ss *= fn[n-1-(p-i)] - 1 ) %= mm;
        ( ans += ss ) %= mm;
    }
}

void work()
{
    rep(i,1,n) deal( i );
    cout << ( ans + mm ) % mm << endl;
}

int main()
{
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}