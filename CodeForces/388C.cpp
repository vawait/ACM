/*
 * Author:  vawait
 * Created Time:  2015/2/28 13:22:23
 * Problem: CodeForces_388C
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
int n , m , s , sum , first , a[10000] , q[10000];

void init()
{
    m = sum = first = 0;
    rep(p,1,n) {
        scanf("%d",&s);
        rep(i,1,s) scanf("%d",&a[i]) , sum += a[i];
        if ( s & 1 ) {
            q[++m] = a[(s+1)/2];
            rep(i,1,s/2) first += a[i];
            rep(i,s/2+2,s) first -= a[i];
        } else {
            rep(i,1,s) if ( i <= s / 2 ) first += a[i]; else first -= a[i];
        }
    }
    if ( m ) sort( q + 1 , q + m + 1 );
}

void work()
{
    int v = 1;
    red(i,m,1) {
        if ( v ) first += q[i]; else first -= q[i];
        v ^= 1;
    }
    first = ( first + sum ) / 2;
    printf("%d %d\n",first,sum-first);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
