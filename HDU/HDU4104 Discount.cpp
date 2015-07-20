/*
 * Author:  vawait
 * Created Time:  2015/7/20 14:26:44
 * Problem: HDU4104 Discount
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
int n , a[1100];

void init()
{
    int sum = 0;
    rep(i,1,n) scanf("%d",&a[i]);
    sort( a + 1 , a + n + 1 );
    rep(i,1,n) if ( a[i] <= sum + 1 ) sum += a[i];
    cout << sum + 1 << endl;
}

void work()
{
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
