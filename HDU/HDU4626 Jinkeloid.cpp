/*
 * Author:  vawait
 * Created Time:  2015/9/14 21:32:56
 * Problem: HDU4626 Jinkeloid
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
const int mx = ( 1 << 20 ) - 1;
int n;
lint sum[1<<20] , f[1<<20];
char a[101000];

void init()
{
    int x = 0;
    scanf("%s",a+1);
    n = strlen( a + 1 );
    clr( sum , 0 );
    sum[0] = 1;
    rep(i,1,n) sum[x^=1<<a[i]-'a'] ++;
    rep(i,0,19)
        rep(j,0,mx) if ( j >> i & 1 ) 
            sum[j^(1<<i)] += sum[j];
}

void work()
{
    int q , m;
    lint ans;
    for ( cin >> q; q; q-- ) {
        scanf("%d",&n);
        ans = m = 0;
        rep(i,1,n) scanf("%s",a) , m |= 1 << a[0] - 'a';
        for ( int x = m; x >= 0; x = x ? m & ( x - 1 ) : -1 ) {
            f[x] = sum[x];
            for ( int y = m; y >= 0; y = y ? m & ( y - 1 ) : -1 ) if ( ( y & x ) == x && y != x ) f[x] -= f[y];
            ans += f[x] * ( f[x] - 1 );
        }
        ans >>= 1;
        printf("%I64d\n",ans);
    }
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
