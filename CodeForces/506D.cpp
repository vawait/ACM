/*
 * Author:  vawait
 * Created Time:  2015/3/26 14:41:57
 * Problem: CodeForces_506D
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
const int maxn = 101000;
int n , m , sg , vis[maxn] , fa[maxn] , q[maxn];
int ask , ax[maxn] , ay[maxn] , ans[maxn];
vector < int > g[maxn];

int find(int t) {
    return fa[t] == t ? t : ( fa[t] = find( fa[t] ) );
}

struct nodd {
    int a , b , c;
} a[maxn];

bool cmp(nodd a,nodd b) {
    return a.c < b.c;
}

void init()
{
    rep(i,1,m) scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
    sort( a + 1 , a + m + 1 , cmp );
    a[0].c = a[1].c - 1;
    scanf("%d",&ask);
    rep(i,1,ask) scanf("%d%d",&ax[i],&ay[i]);
    clr( ans , 0 );
    clr( vis , 0 );
}

void work()
{
    map < pair < int , int > , int > h;
    rep(i,1,m) if ( a[i].c != a[i-1].c ) {
        int x = i , y , s = 0 , vv = 0;
        while ( x < m && a[x+1].c == a[i].c ) x ++;
        rep(j,i,x) {
            y = a[j].a;
            if ( vis[y] != i ) vis[y] = i , q[++s] = y;
            y = a[j].b;
            if ( vis[y] != i ) vis[y] = i , q[++s] = y;
        }
        rep(j,1,s) fa[q[j]] = q[j] , g[q[j]].clear();
        rep(j,i,x) fa[find(a[j].a)] = find( a[j].b );
        rep(j,1,s) g[find(q[j])].pb( q[j] );
        rep(j,1,s) if ( fa[q[j]] == q[j] ) {
            int y = q[j] , sum = g[q[j]].size() - 1;
            if ( sum <= 100 ) {
                rep(k,0,sum)
                    rep(r,k+1,sum) h[mp(g[y][k],g[y][r])] ++;
                rep(k,0,sum) vis[g[y][k]] = 0;
            } else {
                vv = 1;
            }
        }
        if ( vv ) rep(k,1,ask) if ( vis[ax[k]] == i && vis[ay[k]] == i ) 
            ans[k] += ( fa[ax[k]] == fa[ay[k]] );
    }
    
    rep(i,1,ask) {
        int x = ax[i] , y = ay[i];
        printf("%d\n",ans[i]+h[mp(x,y)]+h[mp(y,x)]);
    }
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
