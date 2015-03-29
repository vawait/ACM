/*
 * Author:  vawait
 * Created Time:  2015/3/29 12:57:57
 * Problem: CodeForces_327D
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
int n , m , sum , ax[1001000] , ay[1001000];
int dx[] = { -1 , 1 , 0 , 0 };
int dy[] = { 0 , 0 , -1 , 1 };
char a[600][600] , ans[1001000];

void init()
{
    rep(i,1,n) scanf("%s",a[i]+1);
    sum = 0;
}

void dfs(int x,int y,int ty)
{
    sum ++;
    ans[sum] = 'B';
    ax[sum] = x; ay[sum] = y;
    a[x][y] = 'B';
    rep(i,0,3) if ( a[x+dx[i]][y+dy[i]] == '.' )
        dfs( x + dx[i] , y + dy[i] , 2 );
    if ( ty == 2 ) {
        sum ++;
        ans[sum] = 'D';
        ax[sum] = x , ay[sum] = y;
        sum ++;
        ans[sum] = 'R';
        ax[sum] = x , ay[sum] = y;
        a[x][y] = 'R';
    }
}

void work()
{
    rep(i,1,n) 
        rep(j,1,m) if ( a[i][j] == '.' ) {
            dfs( i , j , 1 );
        }
    printf("%d\n",sum);
    rep(i,1,sum) printf("%c %d %d\n",ans[i],ax[i],ay[i]);
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
