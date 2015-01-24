/*
 * Author:  vawait
 * Created Time:  2015/1/23 23:56:47
 * Problem: CodeForces_507A
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
int n , m , b[10000];
pair < int , int > a[100000];

void init()
{
    rep(i,1,n) scanf("%d",&a[i].x) , a[i].y = i;
    sort( a + 1 , a + 1 + n );
}

void work()
{
    int sum = 0;
    rep(i,1,n) if ( m >= a[i].x ) b[++sum] = a[i].y , m -= a[i].x;
    printf("%d\n",sum);
    rep(i,1,sum) {
        if ( i < sum ) printf("%d ",b[i]); else printf("%d\n",b[i]);
    }
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
