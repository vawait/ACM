/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月09日 星期日 13时46分49秒
 * File Name: HDU_4028
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define db pop_back
typedef long long lint;
int n , a[] = { 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 };
int s[50][10] , d[50];
lint m , f[45][6][4][3][1024] , f2[10] , f3[10] , f5[10] , fn[1024];

void init()
{
    lint x;
    rep(i,1,40) {
        rep(j,2,5) {
            int k = i;
            s[i][j] = 0;
            while ( k % j == 0 ) s[i][j] ++ , k /= j;
        }
        rep(j,0,8) if ( i % a[j] == 0 ) d[i] |= 1 << j;
    }

    f2[0] = f3[0] = f5[0] = fn[0] = 1;
    rep(i,1,8) f2[i] = f2[i-1] * 2 , f3[i] = f3[i-1] * 3 , f5[i] = f5[i-1] * 5;
    rep(i,1,511) 
        rep(j,0,8) if ( ( i >> j ) & 1 ) {
            fn[i] = a[j] * fn[i^(1<<j)];
            break;
        }

    f[1][0][0][0][0] = 1;
    rep(i,1,40) rep(j,0,5)
        rep(k,0,3) rep(l,0,2)
            rep(r,0,512) if ( ( x = f[i][j][k][l][r] ) > 0 ) {
                f[i+1][j][k][l][r] += x;
                f[i+1][max(j,s[i][2])][max(k,s[i][3])][max(l,s[i][5])][r|d[i]] += x;
            }
}

void work()
{
    int t;
    cin >> t;
    rep(cas,1,t) {
        lint x , ans = 0;
        scanf("%d%I64d",&n,&m);
        rep(i,0,5) rep(j,0,3)
            rep(k,0,2) rep(r,0,511) if ( ( x = f[n+1][i][j][k][r] ) > 0 && f2[i] * f3[j] * f5[k] * fn[r] >= m ) 
                ans += x;
        if ( m == 1 ) ans --;
        printf("Case #%d: %I64d\n",cas,ans);
    }
}

int main()
{
    init();
    work();
    return 0;
}
