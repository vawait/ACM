/*
 * Author:  vawait
 * Created Time:  2015/8/22 13:18:34
 * Problem: Aizu2555 Everlasting Zero
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
int n , m , a[110][110] , mx[110] , mi[110];
char s[10];
pair < int , int > g[110][110];

void init()
{
    int l , r , x;
    rep(i,1,m) {
        rep(j,1,n) mx[j] = 110 , mi[j] = 0;
        scanf("%d",&x);
        while ( x -- ) {
            scanf("%d%s%d",&l,s,&r);
            if ( s[0] == '>' ) mi[l] = max( mi[l] , r );
            else mx[l] = min( mx[l] , r );
        }
        rep(j,1,n) g[i][j] = mp( mi[j] , mx[j] );
    }
}

void work()
{
    rep(i,1,m)
        rep(j,1,n) if ( g[i][j].x > g[i][j].y ) {
            puts("No");
            return;
        }
    clr( a , 0 );
    rep(i,1,m)
        rep(j,1,m) 
            rep(k,1,n) if ( g[i][k].y < g[j][k].x ) a[i][j] = 1;
    rep(k,1,m)
        rep(i,1,m)
            rep(j,1,m) if ( a[i][k] && a[k][j] ) a[i][j] = 1;
    rep(i,1,m) if ( a[i][i] ) {
        puts("No");
        return;
    }
    puts("Yes");
}

int main()
{
    while ( cin >> m >> n ) {
        init();
        work();
    }
    return 0;
}
