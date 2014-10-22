/*
 * Author:  vawait
 * Created Time:  2014/10/16 15:26:19
 * File Name: BZOJ3029.cpp
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
int n , l , k , a[400] , now = 0 , nex = 1;
const int mm = 205;
double f[2][420][210] , p[210];

void init()
{
    scanf("%d%d%d",&n,&l,&k);
    rep(i,1,n) scanf("%lf",&p[i]) , p[i] /= 100;
    rep(i,1,n) scanf("%d",&a[i]);
    rep(j,0,n+mm)
        rep(k,0,n) f[now][j][k] = 0;
    f[now][min(k,n)+mm][0] = 1;
}

void work()
{
    rep(i,0,n-1) {
        rep(j,0,n+mm)
            rep(k,0,n) f[nex][j][k] = 0;
        rep(j,1,n+mm)
            rep(k,0,n) if ( f[now][j][k] > 0 ) {
                f[nex][j][k] += f[now][j][k] * ( 1 - p[i+1] );
                if ( a[i+1] == -1 ) {
                    f[nex][j-1][k+1] += f[now][j][k] * p[i+1];
                } else {
                    f[nex][min(n+mm,j+a[i+1])][k+1] += f[now][j][k] * p[i+1]; 
                }
            }
        swap( now , nex );
    }
    double ans = 0;
    rep(i,mm,n+mm)
        rep(j,l,n) ans += f[now][i][j];
    printf("%.6lf\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
