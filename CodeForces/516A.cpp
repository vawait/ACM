/*
 * Author:  vawait
 * Created Time:  2015/2/18 0:15:45
 * Problem: CodeForces_516A
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
int n , a[100];
char c[100];

void deal(int n)
{
    rep(i,2,10) while ( n % i == 0 ) a[i]++ , n /= i;
}

void calc(int n)
{
    rep(i,2,n) deal( i );
}

void init()
{
    clr( a , 0 );
    scanf("%s",c+1);
    rep(i,1,n) calc( c[i] - '0' );
}

void del(int n)
{
    rep(i,2,10) while ( n % i == 0 ) a[i]-- , n /= i;
}

void work()
{
    red(i,10,2) while ( a[i] > 0 ) {
        printf("%d",i);
        red(j,i,2) del( j );
    }
    puts("");
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
