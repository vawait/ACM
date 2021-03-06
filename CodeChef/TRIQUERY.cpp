/*
 * Author:  vawait
 * Created Time:  2014/10/29 20:42:39
 * File Name: CodeChefTRIQUERY.cpp
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
const int maxn = 301000;
const int maxm = 900000;
int n , q , xx[maxn] , yy[maxn] , x[maxn] , y[maxn] , d[maxn];
int ans[maxn];
vector < int > Q1[maxm+10] , Q2[maxm+10] , a[maxm+10];

struct bit
{
    int t[maxn+10];
    void add(int x,int y) {
        for ( ; x <= maxn; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
} T[2];


void init()
{
    rep(i,0,maxm) Q1[i].clear() , Q2[i].clear() , a[i].clear();
    clr( T[1].t , 0 );
    clr( T[0].t , 0 );
    clr( ans , 0 );
    rep(i,1,n) {
        scanf("%d%d",&xx[i],&yy[i]);
        a[xx[i]+yy[i]].pb( i );
    }
    rep(i,1,q) {
        scanf("%d%d%d",&x[i],&y[i],&d[i]);
        Q1[x[i]+y[i]-1].pb( i );
        Q2[x[i]+y[i]+d[i]].pb( i );
    }
}

void work()
{
    int sum = 0 , p;
    rep(i,1,maxm) {
        red(j,a[i].size()-1,0) {
            p = a[i][j];
            T[0].add( xx[p] , 1 );
            T[1].add( yy[p] , 1 );
            sum ++;
        }
        red(j,Q1[i].size()-1,0) {
            p = Q1[i][j];
            ans[p] -= sum - T[0].sum( x[p] - 1 ) - T[1].sum( y[p] - 1 );
        }
        red(j,Q2[i].size()-1,0) {
            p = Q2[i][j];
            ans[p] += sum - T[0].sum( x[p] - 1 ) - T[1].sum( y[p] - 1 );
        }
    }
    rep(i,1,q) printf("%d\n",ans[i]);
}

int main()
{
    while ( cin >> n >> q ) {
        init();
        work();
    }
    return 0;
}
