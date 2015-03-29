/*
 * Author:  vawait
 * Created Time:  2015/3/29 15:09:08
 * Problem: CodeForces_328A
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
int n , a[100] , b[100];
char s1[1000] , s2[1000];

void deal(char *s1,int *a)
{
    rep(i,1,n) {
        if ( s1[i] == '2' || s1[i] == '5' ) {
            a[5] ++;
        } else if ( s1[i] == '6' || s1[i] == '9' ) {
            a[9] ++;
        } else {
            a[s1[i]-'0'] ++;
        }
    }
}

void init()
{
    clr( a , 0 );
    clr( b , 0 );
    n = strlen( s1 + 1 );
    deal( s1 , a );
    n = strlen( s2 + 1 );
    deal( s2 , b );
}

void work()
{
    int mx = 1e9;
    rep(i,0,9) if ( a[i] ) mx = min( mx , b[i] / a[i] );
    cout << mx << endl;
}

int main()
{
    while ( scanf("%s%s",s1+1,s2+1) != EOF ) {
        init();
        work();
    }
    return 0;
}
