/*
 * Author:  vawait
 * Created Time:  2015/2/23 15:48:17
 * Problem: test.cpp
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
int n , ans , f[110][2] , v[100];
char b[] = { 'R' , 'G' , 'B' , 'Y' , 'W' , '1' , '2' , '3' , '4' , '5' };
char a[110][4];

void init()
{
    ans = 10;
    rep(i,1,n) scanf("%s",a[i]+1);
    int s = n;
    n = 1;
    rep(i,2,s) if ( a[i][1] != a[n][1] || a[i][2] != a[n][2] ) {
        n ++;
        a[n][1] = a[i][1];
        a[n][2] = a[i][2];
    }
}

void deal(char c)
{
    rep(i,1,n)
        rep(j,1,2) if ( a[i][j] == c ) {
            f[i][j] = 1;
            if ( f[i][1] && f[i][2] ) v[i] = 1;
        }
}

bool ok()
{
    int fff = 1;
    while ( fff ) {
        fff = 0;
        rep(i,1,n) if ( !v[i] ) {
            rep(j,1,2) if ( f[i][j] ) {
                int vis = 1;
                rep(k,1,n) if ( !v[k] && a[i][j] == a[k][j] && a[i][3-j] != a[k][3-j] ) vis = 0;
                if ( vis ) {
                    fff = 1; 
                    v[i] = 1;
                }
            }
            if ( fff ) break;
        }
    }
    rep(i,1,n) if ( !v[i] )
        rep(j,i+1,n) if ( !v[j] && ( a[i][1] != a[j][1] || a[i][2] != a[j][2] ) ) return 0;
    return 1;
}

void work()
{
    rep(i,0,1023) {
        int s = 0;
        clr( f , 0 );
        clr( v , 0 );
        rep(j,0,9) if ( ( i >> j ) & 1 ) s ++ , deal( b[j] );
        if ( ok() && s < ans ) ans = s;
    }
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
