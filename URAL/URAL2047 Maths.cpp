/*
 * Author:  vawait
 * Created Time:  2015/8/25 13:10:30
 * Problem: URAL2047 Maths
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
const int maxn = 2000000;
bool vis[maxn+10];
int ans[maxn];
lint f[maxn+10] , pri[maxn+10];

void init()
{
    rep(i,1,maxn) pri[i] = 1;
    rep(i,1,300) f[i] = 1;
    rep(i,2,maxn) if ( !vis[i] ) {
        for ( int j = i; j <=maxn ; j += i ) {
            int s = 0 , x = j;
            while ( x % i == 0 ) x /= i , s ++;
            if ( pri[j] < 1000 ) pri[j] *= ( s + 1 );
            vis[j] = 1;
        }
    }
    rep(i,2,maxn) if ( pri[i] <= 300 && pri[i] < i && f[i-pri[i]] ) f[i] = f[i-pri[i]] + 1;
}

void work()
{
    int n , p;
    scanf("%d",&n);
    rep(i,1,maxn) if ( f[i] == n ) p = i;
    red(i,n,1) {
        ans[i] = pri[p];
        p -= pri[p];
    }
    rep(i,1,n) {
        printf("%d",ans[i]);
        if ( i < n ) printf(" ");
    }
}

int main()
{
    init();
    work();
    return 0;
}
