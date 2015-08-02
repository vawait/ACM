/*
 * Author:  vawait
 * Created Time:  2015/8/2 14:13:45
 * Problem: HDU4349 Xiao Ming's Hope
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

void init()
{
    int n , x;
    while ( cin >> n ) {
        x = 0;
        while ( n ) {
            if ( n & 1 ) x ++;
            n >>= 1;
        }
        printf("%d\n",1<<x);
    }
}

void work()
{
}

int main()
{
    init();
    work();
    return 0;
}
