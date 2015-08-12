/*
 * Author:  vawait
 * Created Time:  2015/8/12 12:58:52
 * Problem: Gym100379D Generalized Fibonacci sequence
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
lint n , ans;

void init()
{
    ans = 0;
}

void calc(lint a,lint b)
{
    int s = 1;
    while ( a < b ) {
        b -= a;
        swap( a , b );
        s ++;
    }
    ans += s;
}

void work()
{
    rep(i,1,n-1) calc( n - i , i );
    cout << ans << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
