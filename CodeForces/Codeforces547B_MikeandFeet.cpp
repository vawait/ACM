/*
 * Author:  vawait
 * Created Time:  2015/5/27 1:10:20
 * Problem: Codeforces547B Mike and Feet
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
const int maxn = 301000;
int n , f[maxn] , L[maxn] , R[maxn] , ans[maxn] , use[maxn];
pair < int , int > a[maxn];

void init()
{
    rep(i,1,n+1) L[i] = R[i] = f[i] = i , ans[i] = 0 , use[i] = 0;
    rep(i,1,n) scanf("%d",&a[i].x) , a[i].y = i;
    sort( a + 1 , a + n + 1 );
}

int find(int t)
{
    return f[t] == t ? t : f[t] = find( f[t] );
}

void deal(int x,int y)
{
    x = find( x );
    y = find( y );
    if ( x != y ) {
        L[x] = min( L[x] , L[y] );
        R[x] = max( R[x] , R[y] );
        f[y] = x;
    }
}

void work()
{
    red(i,n,1) {
        int id = a[i].y;
        use[id] = 1;
        if ( use[id-1] ) deal( id , id - 1 );
        if ( use[id+1] ) deal( id , id + 1 );
        id = find( id );
        ans[R[id]-L[id]+1] = max( ans[R[id]-L[id]+1] , a[i].x );
    }
    red(i,n-1,1) ans[i] = max( ans[i] , ans[i+1] );
    rep(i,1,n) printf("%d ",ans[i]);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
