/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月07日 星期五 15时44分13秒
 * File Name: HDU_4282
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define db pop_back
typedef long long lint;
int n;
lint sum , a;

void init()
{
    sum = 0;
}

lint km(lint a,lint n)
{
    lint s = 1;
    while ( n ) {
        if ( n & 1 ) s *= a;
        a *= a;
        n >>= 1;
    }
    return s;
}

void work()
{
    rep(z,2,30) {
        lint y = exp( log( n * 1.0 ) / z ) + 1;
        rep(x,1,y) {
            while ( y >= 2 && ( a = km( x , z ) + km( y , z ) + z * x * y ) > n ) y --;
            if ( x >= y ) break;
            if ( a == n ) sum ++;
        }
    }
    cout << sum << endl;
}

int main()
{
    while ( scanf("%d",&n) && n ) {
        init();
        work();
    }
    return 0;
}
