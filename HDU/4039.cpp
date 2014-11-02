/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月02日 星期日 13时32分15秒
 * File Name: HDU4039.cpp
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define db pop_back
typedef long long lint;
int n , q , sum , a[2010][2010] , len[2010] , d[2010] , b[2010];
char s[2100][20] , c[20];
vector < int > g[2010];

int id()
{
    int l = strlen( c + 1 ) , v;
    rep(i,1,sum) if ( len[i] == l ) {
        v = 1;
        rep(j,1,len[i]) if ( s[i][j] != c[j] ) v = 0;
        if ( v ) return i;
    }
    len[++sum] = l;
    g[sum].clear();
    rep(i,1,l) s[sum][i] = c[i];
    return sum;
}

void init()
{
    int x , y;
    scanf("%d%d",&n,&q);
    rep(i,1,n+n)
        rep(j,1,n+n) a[i][j] = 0;
    sum = 0;
    rep(i,1,n) {
        scanf("%s",c+1);
        x = id();
        scanf("%s",c+1);
        y = id();
        a[x][y] = a[y][x] = 1;
        g[x].pb( y );
        g[y].pb( x );
    }
}

bool cmp(int x,int y)
{
    int l = min( len[x] , len[y] );
    rep(i,1,l) if ( s[x][i] < s[y][i] ) return 1;
    else if ( s[x][i] > s[y][i] ) return 0;
    return len[x] < len[y];
}

void work()
{
    int t , x , y , mx , ss;
    while ( q -- ) {
        scanf("%s",c+1);
        t = id();
        rep(i,1,sum) d[i] = 0;
        red(i,g[t].size()-1,0) {
            x = g[t][i];
            red(j,g[x].size()-1,0) {
                y = g[x][j];
                if ( y != t && !a[t][y] ) d[y] ++;
            }
        }
        mx = 0;
        rep(i,1,sum) if ( i != t ) mx = max( mx , d[i] );
        if ( !mx ) {
            puts("-");
        } else {
            ss = 0;
            rep(i,1,sum) if ( d[i] == mx ) b[++ss] = i;
            sort( b + 1 , b + ss + 1 , cmp );
            rep(i,1,ss-1) {
                x = b[i];
                rep(j,1,len[x]) printf("%c",s[x][j]);
                printf(" ");
            }
            x = b[ss];
            rep(j,1,len[x]) printf("%c",s[x][j]);
            puts("");
        }
    }
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case %d:\n",i);
        init();
        work();
    }
    return 0;
}
