/*
 * Author:  vawait
 * Created Time:  2015/9/3 13:00:25
 * Problem: Gym100337F "Money, Money, Money"
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
lint n;

void init()
{
    if ( n & 1 ) 
        cout << "2 " << n + 2 << endl; 
    else 
        puts("0 0");
}

void work()
{
}

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
