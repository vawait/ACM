/*
 * Author:  vawait
 * Created Time:  2015/2/23 14:49:59
 * Problem: test.cpp
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
int n , m , sum , a[3010] , f[3010];

void calc()
{
    sum = 0;
    clr( f , 0 );
    rep(i,1,n) if ( !f[i] ) {
        f[i] = i;
        if ( a[i] == i ) continue;
        for ( int j = a[i]; !f[j]; j = a[j] ) f[j] = i , sum ++;
    }
}

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&m);
    calc();
}

void work()
{
    printf("%d\n",abs(m-sum));
    while ( sum > m ) {
        rep(i,1,n) if ( a[i] != i ) {
            int p = n;
            rep(j,i+1,n) if ( f[j] == f[i] && j < p ) p = j;
            printf("%d %d ",i,p);
            swap( a[i] , a[p] );
            break;
        }
        calc();
    }
    while ( sum < m ) {
        rep(i,1,n) if ( f[1] != f[i] ) {
            printf("%d %d ",1,i);
            swap( a[1] , a[i] );
            break;
        }
        calc();
    }
    //puts("");
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
