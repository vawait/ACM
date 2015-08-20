/*
 * Author:  vawait
 * Created Time:  2015/8/19 12:31:06
 * Problem: Gym100418A A+-B
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
lint a , b;

void init()
{
    if ( ( a >= 0 ) == ( b >= 0 ) ) {
        cout << a - b << endl;
    } else 
        cout << a + b << endl;
}

void work()
{
}

int main()
{
    while ( cin >> a >> b ) {
        init();
        work();
    }
    return 0;
}
