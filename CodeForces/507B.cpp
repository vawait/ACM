/*
 * Author:  vawait
 * Created Time:  2015/1/24 0:08:40
 * Problem: CodeForces_507B
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
lint r , x, y , xx , yy;

void init()
{
    r *= 2;
    cout << ceil( sqrt( sqr( x - xx ) + sqr( y - yy ) ) * 1.0 / r ) << endl; 
}

void work()
{
}

int main()
{
    while ( cin >> r >> x >> y >> xx >> yy ) {
        init();
        work();
    }
    return 0;
}
