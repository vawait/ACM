/*
 * Author:  vawait
 * Created Time:  2014/10/29 20:59:00
 * File Name: CodeChefRRDAG.cpp
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
int n , ans , d[1510] , v[1510];
char a[1510][1510];

void init()
{
    rep(i,1,n) scanf("%s",a[i]+1);
    ans = n * ( n - 1 ) / 2;
    clr( d , 0 );
    clr( v , 0 );
    rep(i,1,n)
        rep(j,1,n) if ( a[i][j] == '1' ) d[i] ++ , ans --;
}

void work()
{
    int x;
    priority_queue < int > q;
    rep(i,1,n) if ( !d[i] ) q.push( i );
    while ( !q.empty() ) {
        x = q.top(); q.pop();
        rep(i,1,n) if ( a[i][x] == '1' ) 
            if ( !( -- d[i] ) ) q.push( i );
        v[x] = 1;
        rep(i,1,n) if ( !v[i] && a[i][x] == '0' ) a[i][x] = '2';
    }
    printf("%d\n",ans);
    rep(i,1,n)
        rep(j,1,n) if ( a[i][j] == '2' ) printf("%d %d\n",i,j);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
