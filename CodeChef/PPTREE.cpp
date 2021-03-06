/*
 * Author:  vawait
 * Created Time:  2014/10/30 15:28:48
 * File Name: CodeChef_PPTREE.cpp
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
int n , ans , s;
vector < pair < int , int > > a[maxn];

struct nodd
{
    int a[2];
    void cl() {
        a[0] = a[1] = 0;
    }
} f[maxn*30];

void add(int v)
{
    int p = 1 , k;
    red(i,29,0) {
        k = ( 1 << i ) & v ? 1 : 0;
        if ( !f[p].a[k] ) {
            f[p].a[k] = ++s;
            f[s].cl();
        }
        p = f[p].a[k];
    }
}

void init()
{
    int x , y , d;
    scanf("%d",&n);
    rep(i,1,n) a[i].clear();
    rep(i,2,n) {
        scanf("%d%d%d",&x,&y,&d);
        a[x].pb( mp( y , d ) );
        a[y].pb( mp( x , d ) );
    }
    ans = 0;
    s = 1;
    f[s].cl();
    add( 0 );
}

int ask(int v)
{
    int p = 1 , k;
    red(i,29,0) {
        k = ( 1 << i ) & v ? 1 : 0;
        if ( f[p].a[1^k] ) k ^= 1;
        if ( k ) v ^= ( 1 << i );
        p = f[p].a[k];
    }
    return v;
}

void dfs(int t,int fa,int v)
{
    add( v );
    ans = max( ans , ask( v ) );
    red(i,a[t].size()-1,0) if ( a[t][i].x != fa )
        dfs( a[t][i].x , t , v ^ a[t][i].y );
}

void work()
{
    dfs( 1 , 0 , 0 );
    printf("%d\n",ans);
}

int main()
{
    int t;
    for ( cin >> t; t; t -- ) {
        init();
        work();
    }
    return 0;
}
