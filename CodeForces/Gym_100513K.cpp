/*
 * Author:  vawait
 * Created Time:  2015/5/21 13:55:37
 * Problem: Gym_100513K
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
int n , f[2100] , a[2100][2100];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) f[i] = i;
    rep(i,1,n)
        rep(j,1,n) scanf("%d",&a[i][j]);
}

int find(int t)
{
    return f[t] == t ? t : f[t] = ( find( f[t] ) );
}

void work()
{
    rep(j,1,n)
        rep(i,1,n) if ( find( i ) != find( a[i][j] ) ) {
            int x = a[i][j];
            rep(k,1,n) if ( find( i ) == find( a[x][k] ) ) {
                int y = a[x][k];
                printf("%d %d\n",x,y);
                f[find(x)] = y;
                break;
            }
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
