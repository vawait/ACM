/*
 * Author:  vawait
 * Created Time:  2015/3/27 0:34:38
 * Problem: CodeForces_525A
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
int n , s[100];
char a[401000];

void init()
{
    scanf("%s",a+1);
    n = strlen( a + 1 );
    clr( s , 0 );
}

void work()
{
    int sum = 0;
    rep(i,1,n) if ( i & 1 ) {
        s[a[i]-'a'] ++;
    } else {
        if ( !s[a[i]-'A'] ) sum ++; else s[a[i]-'A'] --;
    }
    cout << sum << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
