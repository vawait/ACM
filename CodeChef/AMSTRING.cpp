/*
 * Author:  vawait
 * Created Time:  2014/10/30 16:27:25
 * File Name: CodeChef_AMSTRING.cpp
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
int n , m , ans;
char a[1100] , b[1100];

void init()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",a+1,b+1);
    ans = 0;
}

void deal(int l1,int r1,int l2,int r2)
{
    int s = 0;
    for ( ; r1 <= n && r2 <= n; r1 ++ , r2 ++ ) {
        s += a[r1] != b[r2];
        while ( s > m ) {
            s -= a[l1] != b[l2];
            l1 ++;
            l2 ++;
        }
        ans += r1 - l1 + 1;
    }
}

void work()
{
    rep(i,1,n) deal( 1 , 1 , i , i );
    rep(i,2,n) deal( i , i , 1 , 1 );
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
