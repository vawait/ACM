/*
 * Author:  vawait
 * Created Time:  2015/8/31 13:08:20
 * Problem: Gym100341J Triatrip
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
int n , m;
lint g[310][310];

void init()
{
    int x , y , d;
    lint len;
    clr( g , 1 );
    scanf("%d%d",&n,&m);
    rep(i,1,n) g[i][i] = 0;
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&d);
        len = lint( d ) * 100000LL + 1;
        g[x][y] = g[y][x] = min( len , g[x][y] );
    }
}

void work()
{
    lint sum = 0 , num = 0;
    rep(k,1,n)
        rep(i,1,n) rep(j,1,n) g[i][j] = min( g[i][j] , g[i][k] + g[k][j] );
    rep(i,1,n)
        rep(j,i+1,n) sum += g[i][j] % 100000LL , num ++;
    printf("%.9f\n",(double)sum/num);
}

int main()
{
    freopen("trip.in","r",stdin);
    freopen("trip.out","w",stdout);
    init();
    work();
    return 0;
}
