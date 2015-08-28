/*
 * Author:  vawait
 * Created Time:  2015/8/26 16:02:03
 * Problem: URAL1780 Gray Code
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
int n , f[maxn][2] , pre[maxn][2];
char a[maxn] , b[maxn];

void init()
{
    scanf("%s",a+1);
    scanf("%s",b+1);
    n = strlen( a + 1 );
    a[0] = a[n+1] = '0';
    f[0][0] = 1;
    rep(i,1,n)
        rep(j,0,1) if ( a[i] == j + '0' || a[i] == '?' ) {
            rep(k,0,1) if ( f[i-1][k] ) {
                int x = k ^ j;
                if ( b[i] == '?' || b[i] == x + '0' ) f[i][j] += f[i-1][k] , pre[i][j] = k;
            }
            f[i][j] = min( f[i][j] , 10 );
        }
}

void work()
{
    int sum = f[n][0] + f[n][1];
    if ( !sum ) {
        puts("Impossible");
    } else if ( sum > 1 ) {
        puts("Ambiguity");
    } else {
        int p = f[n][0] ? 0 : 1;
        red(i,n,1) {
            a[i] = p + '0';
            p = pre[i][p];
        }
        rep(i,1,n) {
            int x = a[i] - '0' , y = a[i-1] - '0';
            if ( x ^ y ) b[i] = '1'; else b[i] = '0';
        }
        rep(i,1,n) printf("%c",a[i]);
        puts("");
        rep(i,1,n) printf("%c",b[i]);
        puts("");
    }
}

int main()
{
    init();
    work();
    return 0;
}
