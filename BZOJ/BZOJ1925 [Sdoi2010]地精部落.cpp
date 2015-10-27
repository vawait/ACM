/*
 * Author:  vawait
 * Created Time:  2015/9/24 22:44:46
 * Problem: BZOJ1925: [Sdoi2010]地精部落
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
int n , mod , now = 1 , nex = 0 , f[2][4210][2];

void init()
{
    scanf("%d%d",&n,&mod);
    f[now][1][0] = f[now][1][1] = 1;
}

void work()
{
    rep(i,1,n) {
        clr( f[nex] , 0 );
        rep(j,1,i) {
            rep(k,0,1) ( f[now][j][k] += f[now][j-1][k] ) %= mod;
            ( f[nex][j+1][1] += f[now][j][0] ) %= mod;
            ( f[nex][1][0] += f[now][j][1] ) %= mod;
            ( f[nex][j+1][0] -= f[now][j][1] ) %= mod;
        }
        swap( now , nex );
    }
    int ans = 0;
    rep(i,1,n)
        rep(j,0,1) ( ans += f[nex][i][j] ) %= mod;
    if ( n == 1 ) ans = 1;
    ( ans += mod ) %= mod;
    printf("%d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
