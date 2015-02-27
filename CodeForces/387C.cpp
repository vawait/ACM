/*
 * Author:  vawait
 * Created Time:  2015/2/26 15:43:18
 * Problem: CodeForces_387C
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
const int maxn = 1010000;
int n , a[maxn];
char c[maxn];

void init()
{
    scanf("%s",c+1);
    n = strlen( c + 1 );
    rep(i,1,n) a[i] = c[i] - '0';
}

bool ok()
{
    int l = n;
    while ( l && !a[l] ) l--;
    int ans = 1;
    if ( !l || l - 1 < n - l + 1 ) ans = 0;
    if ( l - 1 == n - l + 1 ) {
        rep(i,1,l-1) if ( a[i] != a[i-1+l] ) {
            if ( a[i] < a[i-1+l] ) ans = 0;
            break;
        }
    }
    if ( !ans ) return 0;
    n = l - 1;
    return 1;
}

void work()
{
    int ans = 1;
    while ( n > 1 && ok() ) ans ++;
    printf("%d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}
