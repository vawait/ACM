/*
 * Author:  vawait
 * Created Time:  2014/10/29 15:13:14
 * File Name: CodeChefSHOOTING.cpp
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
int n , m , sn , sm , f[2600] , s[30] , d[30] , p[30][4][60];
pair < int , int > a[2600] , b[30];
char c[60][60];

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",c[i]+1);
    sn = sm = 0;
    rep(i,1,n)
        rep(j,1,m) {
            if ( c[i][j] == 'E' ) a[++sn] = mp( i , j );
            if ( c[i][j] == 'L' ) b[++sm] = mp( i , j );
        }
    clr( s , 0 );
    clr( f , 0 );
    rep(i,1,sm) {
        s[i] ++;
        p[i][s[i]][0] = 0;
        rep(j,1,sn) if ( a[j].x == b[i].x && a[j].y < b[i].y ) p[i][s[i]][++p[i][s[i]][0]] = j;
        if ( !p[i][s[i]][0] ) s[i] --;
        s[i] ++;
        p[i][s[i]][0] = 0;
        rep(j,1,sn) if ( a[j].x == b[i].x && a[j].y > b[i].y ) p[i][s[i]][++p[i][s[i]][0]] = j;
        if ( !p[i][s[i]][0] ) s[i] --;
        s[i] ++;
        p[i][s[i]][0] = 0;
        rep(j,1,sn) if ( a[j].x < b[i].x && a[j].y == b[i].y ) p[i][s[i]][++p[i][s[i]][0]] = j;
        if ( !p[i][s[i]][0] ) s[i] --;
    }
    n = 0;
    rep(i,1,sm) if ( s[i] == 1 ) d[++n] = i;
    rep(i,1,sm) if ( s[i] == 2 ) d[++n] = i;
    rep(i,1,sm) if ( s[i] == 3 ) d[++n] = i;
}

bool dfs(int nn)
{
    int x = d[nn] , y;
    if ( !sn ) return 1;
    if ( nn > n ) return 0;
    rep(i,1,s[x]) {
        rep(j,1,p[x][i][0])
            if ( ( ++f[p[x][i][j]] ) == 1 ) sn --;
        if ( dfs( nn + 1 ) ) return 1;
        rep(j,1,p[x][i][0])
            if ( ( --f[p[x][i][j]] ) == 0 ) sn ++;
    }
    return 0;
}

void work()
{
    rep(i,1,sn) {
        int v = 0;
        rep(j,1,sm) if ( ( a[i].x < b[j].x && a[i].y == b[j].y ) || a[i].x == b[j].x ) v = 1;
        if ( !v ) {
            puts("Impossible");
            return;
        }
    }
    
    puts( dfs( 1 ) ? "Possible" : "Impossible");
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
