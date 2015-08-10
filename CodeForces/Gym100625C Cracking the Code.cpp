/*
 * Author:  vawait
 * Created Time:  2015/8/9 15:21:08
 * Problem: Gym100625C Cracking the Code
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
int n , m , len[1010] , v[1010] , f[110][27] , p1[30] , p2[30];
int g[40][40] , d2[40] , d[40];
char s[110][1010] , a[1010];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%s",s[i]+1) , len[i] = strlen( s[i] + 1 ); 
    scanf("%s",a+1);
    m = strlen( a + 1 );
}

void calc(int k)
{
    v[k] = 0;
    if ( len[k] != m ) return;
    rep(i,0,27) p1[i] = p2[i] = 40;
    int x , y;
    rep(i,1,m) {
        x = s[k][i] - 'a' , y = a[i] - 'a';
        if ( p1[x] < 30 && p1[x] != y ) return;
        if ( p2[y] < 30 && p2[y] != x ) return;
        p1[x] = y;
        p2[y] = x;
    }
    rep(i,0,26) f[k][i] = p1[i];
    v[k] = 1;
}

void work()
{
    rep(i,1,n) calc( i );
    scanf("%s",a+1);
    m = strlen( a + 1 );
    
    int ok = 0;
    rep(i,1,n) if ( v[i] ) ok = 1;
    if ( !ok ) {
        puts("IMPOSSIBLE");
        return;
    }
    
    clr( g , 0 );
    clr( d , 0 );
    clr( d2 , 0 );
    clr( p1 , 1 );
    clr( p2 , 1 );
    rep(i,1,n) if ( v[i] )
        rep(j,0,25) if ( f[i][j] < 30 ) {
            g[j][f[i][j]] = 1;
        }
    rep(i,0,25) 
        rep(j,0,25) if ( g[i][j] ) {
            d[i]++ , d2[j] ++;
            p1[i] = j;
            p2[j] = i;
        }
    
    int s1 = 0 , s2 = 0 , x1 , x2;
    rep(i,0,25) if ( p1[i] > 30 ) s1 ++ , x1 = i;
    rep(i,0,25) if ( p2[i] > 30 ) s2 ++ , x2 = i;
    if ( s1 == 1 && s2 == 1 ) p1[x1] = x2 , p2[x2] = x1 , d[x1] = 1 , d2[x2] = 1;
    
    rep(i,1,m) {
        int x = a[i] - 'a' , y = p1[x];
        if ( d[x] == 1 && d2[y] == 1 && p2[y] == x ) 
            printf("%c",'a'+p1[x]); 
        else 
            printf("?");
    }
    puts("");
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
