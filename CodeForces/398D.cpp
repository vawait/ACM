/*
 * Author:  vawait
 * Created Time:  2015/2/28 16:35:40
 * Problem: CodeForces_398D
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
const int maxn = 50010;
int n , m , Q , o , on[maxn] , f[maxn] , sum[maxn];
vector < int > g[maxn];

void init()
{
    int x , y;
    scanf("%d%d%d",&n,&m,&Q);
    scanf("%d",&o);
    rep(i,1,o) scanf("%d",&x) , on[x] = 1;
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        if ( sum[x] > sum[y] ) swap( x , y );
        sum[x] ++;
        g[x].pb( y );
        f[y] += on[x];
    }
}

void work()
{
    char c[10]; 
    int x , y;
    while ( Q -- ) {
        scanf("%s",&c);
        if ( c[0] == 'O' ) {
            scanf("%d",&x);
            on[x] = 1;
            red(i,g[x].size()-1,0) f[g[x][i]] ++;
        }
        if ( c[0] == 'F' ) {
            scanf("%d",&x);
            on[x] = 0;
            red(i,g[x].size()-1,0) f[g[x][i]] --;
        }
        if ( c[0] == 'A' ) {
            scanf("%d%d",&x,&y);
            if ( sum[x] > sum[y] ) swap( x , y );
            sum[x] ++;
            g[x].pb( y );
            f[y] += on[x];
        }
        if ( c[0] == 'D' ) {
            scanf("%d%d",&x,&y);
            int v = -1;
            red(i,g[x].size()-1,0) if ( g[x][i] == y ) v = i;
            if ( v < 0 ) {
                swap( y , x );
                red(i,g[x].size()-1,0) if ( g[x][i] == y ) v = i;
            }
            if ( on[x] ) f[y] --;
            sum[x] --;
            g[x][v] = g[x][g[x].size()-1];
            g[x].pop_back();
        }
        if ( c[0] == 'C' ) {
            scanf("%d",&x);
            int s = f[x];
            red(i,g[x].size()-1,0) s += on[g[x][i]];
            printf("%d\n",s);
        }
    }
}

int main()
{
    init();
    work();
    return 0;
}
