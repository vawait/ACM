/*
 * Author:  vawait
 * Created Time:  2015/2/23 13:20:46
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
int n , m , k;
pair < int , int > a[100000];

void init()
{
    int s = 0;
    for ( int i = 1; i <= n; i += 2 ) {
        rep(j,1,m) a[++s] = mp( i , j );
        red(j,m,1) a[++s] = mp( i + 1 , j );
    }
}

void work()
{
    int s = 0;
    rep(i,1,k) {
        int p = i == k ? n * m - 2 * ( k - 1 ) : 2;
        printf("%d",p);
        rep(j,1,p) {
            ++s;
            printf(" %d %d",a[s].x,a[s].y);
        }
        puts("");
    }
}

int main()
{
    while ( cin >> n >> m >> k ) {
        init();
        work();
    }
    return 0;
}
