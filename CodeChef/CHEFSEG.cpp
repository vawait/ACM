/*
 * Author:  vawait
 * Created Time:  2014/11/10 12:52:26
 * Problem: CodeCher_CHEFSEG
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
lint x , k , n;

void init()
{
    scanf("%lld%lld",&x,&k);
    n = 1;
}

void work()
{
    while ( n < k ) {
        k -= n;
        n <<= 1;
    }
    n <<= 1; k = k * 2 - 1;
    printf("%.9f\n",1.0*x*k/n);
}

int main()
{
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
