/*
 * Author:  vawait
 * Created Time:  2015/3/27 0:39:42
 * Problem: CodeForces_525B
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
const int maxn = 401000;
int len , n;
lint sum[maxn];
char a[maxn];

void init()
{
    len = strlen( a + 1 );
    scanf("%d",&n);
    clr( sum , 0 );
}

void work()
{
    int x , y;
    while ( n -- ) {
        scanf("%d",&x);
        y = len - x + 1;
        sum[x] ++;
        sum[y+1] --;
    }
    rep(i,1,len) {
        sum[i] += sum[i-1];
        if ( sum[i] & 1 ) printf("%c",a[len-i+1]); else printf("%c",a[i]);
    }
    puts("");
}

int main()
{
    while ( scanf("%s",a+1) != EOF ) {
        init();
        work();
    }
    return 0;
}
