/*
 * Author:  vawait
 * Created Time:  2015/8/26 15:24:05
 * Problem: URAL1776 Anniversary Firework
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
int n;
double f[410][410] , s[410][410];

void init()
{
    cin >> n;
}

void work()
{
    double ans = 0;
    if ( n > 2 ) {
        n -= 2;
        rep(i,1,n) s[0][i] = s[1][i] = 1;
        f[1][1] = 1;
        f[0][0] = 1;
        rep(i,2,n)
            rep(j,1,n) {
                rep(k,1,i) {
                    f[i][j] += f[k-1][j-1] * s[i-k][j-1] + s[k-1][j-1] * f[i-k][j-1] - f[k-1][j-1] * f[i-k][j-1];
                }
                f[i][j] /= i;
                s[i][j] = f[i][j] + s[i][j-1];
            }
        rep(i,1,n) ans += 10.0 * i * f[n][i];
    }
    printf("%.9f\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
