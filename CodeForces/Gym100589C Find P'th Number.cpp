/*
 * Author:  vawait
 * Created Time:  2015/8/8 12:48:34
 * Problem: Gym100589C Find P'th Number
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
    int n , m;
    char s[100];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&m);
    if ( s[0] == 'o' ) {
        printf("%d\n",m*2);
    } else {
        printf("%d\n",m*2-1);
    }
}

void work()
{
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
