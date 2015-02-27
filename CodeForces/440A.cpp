/*
 * Author:  vawait
 * Created Time:  2015/2/23 13:28:44
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
int n , v[110000];

void init()
{
    int a;
    clr( v , 0 );
    rep(i,1,n-1) scanf("%d",&a) , v[a] = 1;
    rep(i,1,n) if ( !v[i] ) printf("%d\n",i);
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
