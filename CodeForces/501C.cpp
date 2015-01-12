/*
 * Author:  vawait
 * Created Time:  2015/1/12 16:57:39
 * Problem: CodeForces_501C
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
const int maxn = 110000;
int n , a[maxn] , f[maxn];
int sum , va[maxn] , vb[maxn];
priority_queue < int > q;

void init()
{
    rep(i,0,n-1) scanf("%d%d",&a[i],&f[i]);
    sum = 0;
    while ( !q.empty() ) q.pop();
    rep(i,0,n-1) if ( a[i] == 1 ) q.push( -i );
}

void work()
{
    int x , y;
    while ( !q.empty() ) {
        x = -q.top(); q.pop();
        if ( a[x] == 0 ) continue;
        y = f[x];
        a[y]--; f[y] ^= x;
        if ( a[y] == 1 ) q.push( -y );
        va[++sum] = x; vb[sum] = y;
    }
    printf("%d\n",sum);
    rep(i,1,sum) printf("%d %d\n",va[i],vb[i]);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
