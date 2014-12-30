/*
 * Author:  vawait
 * Created Time:  2014/12/30 23:09:25
 * Problem: CodeForces_500B
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
int n , a[1000] , f[500] , v[500] , q[500];
char c[500][500];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) f[i] = i , v[i] = 0;
    rep(i,1,n) scanf("%s",c[i]+1);
}

int find(int t)
{
    return f[t] == t ? t : ( f[t] = find( f[t] ) );
}

void work()
{
    rep(i,1,n) 
        rep(j,1,n) if ( i != j && c[i][j] == '1' ) f[find(i)] = find( j );
    rep(i,1,n) find( i );
    rep(i,1,n) if ( !v[f[i]] ) {
        int s = 0 , p = 1;
        rep(j,1,n) if ( f[i] == f[j] ) q[++s] = a[j];
        sort( q + 1 , q + 1 + s );
        rep(j,1,n) if ( f[i] == f[j] ) a[j] = q[p++];
        v[f[i]] = 1;
    }
    rep(i,1,n-1) printf("%d ",a[i]);
    printf("%d\n",a[n]);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
