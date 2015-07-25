/*
 * Author:  vawait
 * Created Time:  2015/7/25 13:16:56
 * Problem: HDU4165 Pills
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
lint h[100];

void init()
{
    h[0] = h[1] = 1;
    rep(i,2,30) {
        h[i] = 0;
        rep(j,0,i-1) h[i] += h[j] * h[i-1-j];
    }
}

void work()
{
    int n;
    while ( scanf("%d",&n) && n ) {
        cout << h[n] << endl;
    }
}

int main()
{
    init();
    work();
    return 0;
}
