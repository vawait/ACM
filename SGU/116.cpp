/*
 * Author:  vawait
 * Created Time:  2015/3/14 13:32:41
 * Problem: SGU_116
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
const int maxn = 10000;
int n , sum = 0 , m = 0 , pri[10000] , v[20000] , a[10000];
int f[10010] , pre[10010];

void init()
{
    scanf("%d",&n);
    rep(i,2,maxn) if ( !v[i] ) {
        pri[++sum] = i;
        for ( int j = i + i; j < maxn; j += i ) v[j] = 1;
    }
    rep(i,2,sum) if ( !v[i] ) a[++m] = pri[i];
    clr( f , 1 );
    f[0] = 0;
}

void work()
{
    rep(i,1,m)
        rep(j,a[i],n) if ( f[j-a[i]] + 1 < f[j] ) {
            f[j] = f[j-a[i]] + 1;
            pre[j] = a[i];
        }
    if ( f[n] > 300 ) {
        puts("0");
        return ;
    }
    cout << f[n] << endl;
    for ( int x = n; x; x -= pre[x] ) printf("%d ",pre[x]);
}

int main()
{
    init();
    work();
    return 0;
}
