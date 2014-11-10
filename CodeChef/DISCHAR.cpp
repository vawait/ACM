/*
 * Author:  vawait
 * Created Time:  2014/11/10 12:02:57
 * Problem: CodeChef_DISCHAR
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
int n , v[26];
char a[101000];

void init()
{
    scanf("%s",a+1);
    n = strlen( a + 1 );
}

void work()
{
    int ans = 0;
    clr( v , 0 );
    rep(i,1,n) v[a[i]-'a'] = 1;
    rep(i,0,25) ans += v[i];
    printf("%d\n",ans);
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
