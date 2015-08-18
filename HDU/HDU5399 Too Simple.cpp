/*
 * Author:  vawait
 * Created Time:  2015/8/18 12:59:09
 * Problem: HDU5399 Too Simple
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
const lint mod = 1e9 + 7;
int n , m , sum , ok , a[110][110] , vis[110];

void init()
{
    ok = 1;
    sum = 0;
    rep(i,1,m) {
        scanf("%d",&a[i][1]);
        if ( a[i][1] != -1 ) {
            rep(j,2,n) scanf("%d",&a[i][j]);
            clr( vis , 0 );
            rep(j,1,n) vis[a[i][j]] = 1;
            rep(j,1,n) if ( !vis[j] ) ok = 0;
        } else sum ++;
    }
}

void work()
{
    if ( !sum && ok ) {
        rep(i,1,n) {
            int p = i;
            red(j,m,1) p = a[j][p];
            if ( p != i ) ok = 0;
        }
    }
    if ( !ok ) {
        puts("0");
        return;
    }
    lint p = 1 , ans = 1;
    rep(i,1,n) ( p *= i ) %= mod;
    rep(i,2,sum) ( ans *= p ) %= mod;
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
