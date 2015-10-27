/*
 * Author:  vawait
 * Created Time:  2015/10/6 14:51:16
 * Problem: SCU4438 Censor
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
const int maxn = 5001000;
int n , m , p[maxn] , pre[maxn] , pp[maxn];
char a[maxn] , b[maxn];

void init()
{
    int j = 0;
    n = strlen( b + 1 );
    m = strlen( a + 1 );
    p[1] = 0;
    rep(i,2,n) {
        while ( j && b[j+1] != b[i] ) j = p[j];
        if ( b[j+1] == b[i] ) j++;
        p[i] = j;
    }
}

void work()
{
    int j = 0 , now = 0;
    rep(i,1,m) {
        pre[i] = now;
        now = i;
        while ( j && b[j+1] != a[i] ) j = p[j];
        if ( b[j+1] == a[i] ) j++;
        pp[i] = j;
        if ( j == n ) {
            while ( j -- ) now = pre[now];
            j = pp[now];
        }
    }
    int sum = 0;
    while ( now ) b[++sum] = a[now] , now = pre[now];
    red(i,sum,1) printf("%c",b[i]);
    puts("");
}

int main()
{
    while ( scanf("%s%s",b+1,a+1) != EOF ) {
        init();
        work();
    }
    return 0;
}
