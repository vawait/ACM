/*
 * Author:  vawait
 * Created Time:  2015/8/15 13:02:59
 * Problem: Gym100203E bits-Equalizer
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
int l1 , l2;
char a[500] , b[500];

void init()
{
    scanf("%s",a+1);
    l1 = strlen( a + 1 );
    scanf("%s",b+1);
    l2 = strlen( b + 1 );
}

void work()
{
    int s0 = 0 , s1 = 0 , t0 = 0 , t1 = 0 , ans = 0;
    int b1 = 0 , b2 = 0;
    if ( l1 != l2 ) {
        puts("-1");
        return;
    }
    rep(i,1,l1) {
        if ( a[i] == '?' ) ans ++; else if ( a[i] != b[i] ) {
            if ( a[i] == '0' ) b1 ++; else b2 ++;
        }
        if ( a[i] == '0' ) s0 ++;
        if ( a[i] == '1' ) s1 ++;
        if ( b[i] == '0' ) t0 ++;
        if ( b[i] == '1' ) t1 ++;
    }
    if ( s1 > t1 ) {
        puts("-1");
        return;
    }
    ans += max( b1 , b2 );
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case %d: ",i);
        init();
        work();
    }
    return 0;
}
