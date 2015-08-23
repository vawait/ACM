/*
 * Author:  vawait
 * Created Time:  2015/8/22 16:45:15
 * Problem: Aizu2564 Tree Reconstruction
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
const int maxn = 600;
int n , m , f[maxn] , sum[maxn];

int find(int t)
{
    return f[t] == t ? t : f[t] = find( f[t] );
}

void init()
{
    int x , y;
    clr( sum , 0 );
    rep(i,1,n) f[i] = i;
    while ( m -- ) {
        scanf("%d%d",&x,&y);
        sum[x] ++;
        f[find(x)] = find( y );
    }
}

void work()
{
    int ans = 0;
    rep(i,1,n) if ( find( i ) == i ) ans ++;
    rep(i,1,n) ans += sum[i] - 1;
    printf("%d\n",ans);
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
