/*
 * Author:  vawait
 * Created Time:  2015/7/26 14:00:19
 * Problem: HDU4260 The End of The World
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
typedef unsigned long long lint;
int a[1000];
lint f[100];
char s[1000];

void init()
{
    f[1] = 1;
    rep(i,2,63) f[i] = f[i-1] * 2 + 1;
    red(i,strlen(s+1),1) a[i] = s[i] - 'A';
}

lint dfs(int n,int c)
{
    if ( n == 1 ) return c != a[n];
    if ( c == a[n] ) return dfs( n - 1 , c );
    return dfs( n - 1 , 3 - c - a[n] ) + 1 + f[n-1];
}

void work()
{
    cout << dfs( strlen( s + 1 ) , 1 ) << endl;
}

int main()
{
    while ( scanf("%s",s+1) && s[1] != 'X' ) {
        init();
        work();
    }
    return 0;
}
