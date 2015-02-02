/*
 * Author:  vawait
 * Created Time:  2015/2/3 0:25:18
 * Problem: CodeForces_512A
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
int n , len[110] , d[40] , low[40] , z[40] , tt , f[40];
char c[110][200];
vector < int > a[40];

void deal(int x,int y)
{
    rep(i,1,min(len[x],len[y])) if ( c[x][i] != c[y][i] ) {
        a[c[x][i]-'a'+1].pb( c[y][i]-'a'+1 );
        d[c[y][i]-'a'+1] ++;
        return;
    }
    //if ( len[x] < len[y] ) a[0].pb( c[y][len[x]+1]
}

void init()
{
    clr( d , 0 );
    rep(i,0,29) a[i].clear();
    rep(i,1,n) scanf("%s",c[i]+1) , len[i] = strlen( c[i] + 1 );
    rep(i,1,n)
        rep(j,i+1,n) deal( i , j );
    tt = 1;
    rep(i,0,29) f[i] = i;
}

int find(int t)
{
    if ( f[t] == t ) return t;
    return f[t] = find( f[t] );
}

bool dfs(int t)
{
    low[t] = ++tt;
    z[t] = 1;
    red(i,a[t].size()-1,0) {
        int y = a[t][i];
        if ( !low[y] ) dfs( y );
        y = find( y );
        if ( z[y] && low[y] < low[t] ) {
            low[t] = low[y];
            f[t] = y;
        }
    }
    z[t] = 0;
    return 0;
}

void work()
{
    clr( low , 0 );
    rep(i,1,26) if ( !low[i] ) dfs( i );
    rep(i,1,26) if ( find( i ) != i ) {
        puts("Impossible");
        return ;
    }
    rep(i,1,n)
        rep(j,i+1,n) if ( len[i] > len[j] ) {
            int v = 1;
            rep(k,1,len[j]) if ( c[i][k] != c[j][k] ) v = 0;
            if ( v ) {
                puts("Impossible");
                return ;
            }
        }
    
    queue < int > q;
    rep(i,1,26) if ( !d[i] ) q.push( i );
    while ( !q.empty() ) {
        int x = q.front(); 
        q.pop();
        printf("%c",x+'a'-1);
        red(i,a[x].size()-1,0) {
            int y = a[x][i];
            d[y]--;
            if ( !d[y] ) q.push( y );
        }
    }
    puts("");
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
