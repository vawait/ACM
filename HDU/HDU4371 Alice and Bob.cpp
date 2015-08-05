/*
 * Author:  vawait
 * Created Time:  2015/8/5 13:23:12
 * Problem: HDU4371 Alice and Bob
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
int n , m , a[200];

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,m) scanf("%d",&a[i]);
    sort( a + 1 , a + m + 1 );
}

void work()
{
    if ( a[1] > n ) {
        puts("Alice");
        return;
    }
    int sum = n / a[1] + 1;
    puts( sum & 1 ? "Alice" : "Bob" );
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
