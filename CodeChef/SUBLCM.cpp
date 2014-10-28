/*
 * Author:  vawait
 * Created Time:  2014/10/28 16:07:07
 * File Name: CodeChefSUBLCM.cpp
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
const int maxn = 1000000;
int n , m = 0 , a[101000] , v[maxn+10] , p[maxn+10];

struct nodd
{
    int x , n;
} b[maxn*4];

void add(int x,int y)
{
    b[++m].x = y; b[m].n = p[x];
    p[x] = m;
}

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    clr( v , 0 );
}

void work()
{
    int ans = -1 , l = 1 , x , y;
    rep(i,1,n) {
        for (int j = p[a[i]]; j; j = b[j].n ) {
            y = b[j].x;
            l = max( l , v[y] + 1 );
            v[y] = i;
        }
        if ( l < i ) ans = max( ans , i - l + 1 );
    }
    printf("%d\n",ans);
}

int main()
{
    int t;
    cin >> t;
    rep(i,2,maxn) if ( !v[i] )
        for ( int j = i; j <= maxn ; j += i ) add( j , i ) , v[j] = 1;
    while ( t -- ) {
        init();
        work();
    }
    return 0;
}
