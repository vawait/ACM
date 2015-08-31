/*
 * Author:  vawait
 * Created Time:  2015/8/31 15:21:32
 * Problem: Gym100341D Dinner Problem
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
int n , m , f[3010][3010] , cost[10] , pre[3010][3010];
char a[3010] , b[3010] , ty[3010][3010] , ans[7000];

void init()
{
    clr( f , 5 );
    f[0][0] = 0;
    rep(i,1,4) scanf("%d",&cost[i]);
    scanf("%s",a+1);
    scanf("%s",b+1);
    n = strlen( a + 1 );
    m = strlen( b + 1 );
    rep(i,1,n) {
        if ( cost[1] <= i * cost[3] ) {
            ty[i][0] = 'b';
            pre[i][0] = 0;
            f[i][0] = cost[1];
        } else {
            ty[i][0] = 'D';
            f[i][0] = cost[3] * i;
        }
    }
}

void work()
{
    rep(j,1,m) {
        pair < int , int > mx;
        f[0][j] = f[0][j-1] + cost[2];
        ty[0][j] = 'I';
        mx = mp( f[0][j] , 0 );
        rep(i,1,n) {
            if ( mx.x + cost[1] < f[i][j] ) {
                f[i][j] = mx.x + cost[1];
                ty[i][j] = 'b';
                pre[i][j] = mx.y;
            }
            if ( a[i] == b[j] && f[i-1][j-1] + cost[4] < f[i][j] ) {
                f[i][j] = f[i-1][j-1] + cost[4];
                ty[i][j] = 'C';
            }
            if ( f[i][j-1] + cost[2] < f[i][j] ) {
                f[i][j] = f[i][j-1] + cost[2];
                ty[i][j] = 'I';
            }
            if ( f[i-1][j] + cost[3] < f[i][j] ) {
                f[i][j] = f[i-1][j] + cost[3];
                ty[i][j] = 'D';
            }
            mx = min( mx , mp( f[i][j] , i ) );
        }
    }
    
    cout << f[n][m] << endl;
    int sum = 0;
    vector < pair < int , int > > g;
    while ( n || m ) {
        if ( ty[n][m] == 'b' ) {
            g.pb( mp( pre[n][m] + 1 , n ) );
            n = pre[n][m];
        } else if ( ty[n][m] == 'D' ) {
            ans[++sum] = 'D';
            n --;
        } else if ( ty[n][m] == 'I' ) {
            ans[++sum] = 'I';
            m --;
        } else {
            ans[++sum] = 'C';
            n --;
            m --;
        }
    }
    n = g.size();
    cout << n << endl;
    sort( g.begin() , g.end() );
    rep(i,0,n-1) printf("%d %d\n",g[i].x,g[i].y);
    red(i,sum,1) printf("%c",ans[i]);
    puts("");
}

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    init();
    work();
    return 0;
}
