/*
 * Author:  vawait
 * Created Time:  2015/9/2 13:23:07
 * Problem: Gym100339E Nice Sequence
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
const int m = 1 << 18;
int n , k , sum[201000];

struct zkw
{
    int a[1001000] , b[1001000];
    void cha(int l,lint k) {
        b[l+m] = a[l+=m] = k;
        for ( int i = l >> 1; i; i >>= 1 ) {
            a[i] = min( a[i<<1] , a[i<<1|1] ); 
            b[i] = max( b[i<<1] , b[i<<1|1] );
        }
    }
    int askmax(int l,int r) {
        int ans = 0;
        l += m - 1; r += m + 1;
        for ( ; l^r^1; l>>=1 , r>>=1 ) {
            if ( ~l&1 ) ans = max( ans , b[l^1] );
            if ( r&1 ) ans = max( ans , b[r^1] );
        }
        return ans;
    }
    int askmin(int l,int r) {
        int ans = 1e9;
        l += m - 1; r += m + 1;
        for ( ; l^r^1; l>>=1 , r>>=1 ) {
            if ( ~l&1 ) ans = min( ans , a[l^1] );
            if ( r&1 ) ans = min( ans , a[r^1] );
        }
        return ans;
    }
} T;


void init()
{
    scanf("%d%d",&n,&k);
}

void work()
{
    int x , ans = 0;
    rep(i,1,n) {
        scanf("%d",&x);
        x ++;
        sum[x] ++;
        T.cha( x , sum[x] );
        if ( x + 1 <= n + 1 && sum[x] < T.askmax( x + 1 , n + 1 ) - k )
            break;
        if ( x - 1 > 0 && T.askmin( 1 , x - 1 ) < sum[x] - k )
            break;
        ans = i;
    }
    cout << ans << endl;
}

int main()
{
    freopen("nice.in","r",stdin);
    freopen("nice.out","w",stdout);
    init();
    work();
    return 0;
}
