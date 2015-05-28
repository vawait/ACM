/*
 * Author:  vawait
 * Created Time:  2015/5/28 22:55:35
 * Problem: HDU5244 inverse
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
int m , n , a[1<<21]; 
lint b[1<<21];

void init()
{
    scanf("%d",&m);
    n = 1 << m;
    rep(i,1,n) scanf("%I64d",&b[i]);
}

void dfs(int l,int m)
{
    if ( !m ) {
        a[l+1] = b[l+1];
        return;
    }
    int len = 1 << ( m - 1 ) , mid = l + len , r = mid + len;
    lint sum = b[r] - b[mid];
    rep(i,l+1,r) if ( i <= mid ) 
        b[i] = ( b[i] + b[i+len] - sum ) >> 1;
    else 
        b[i] -= b[i-len];
    dfs( l , m - 1 );
    dfs( l + len , m - 1 );
}

void work()
{
    dfs( 0 , m );
    rep(i,1,n) printf(" %d",a[i]);
    puts("");
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d:",i);
        init();
        work();
    }
    return 0;
}
