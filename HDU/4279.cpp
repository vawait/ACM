/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月07日 星期五 14时46分18秒
 * File Name: HDU_4279
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
typedef unsigned long long lint;
lint n , m;

lint ask(lint t)
{
    if ( t <= 5 ) return 0;
    t -= 5;
    lint s = 0 , l = 1 , r = sqrt( t / 4.0 ) , k;
    while ( l < r ) {
        k = ( l + r ) >> 1;
        if ( t <= 12 * k || 4 * k * k >= t - 12 * k ) r = k; else l = k + 1;
    }
    if ( l * ( 12 + 4 * l ) < t ) l ++ , r ++;
    l --;
    s = l * ( 6 + 2 * l );
    t -= l * ( 12 + 4 * l );
    rep(i,1,5) if ( t ) {
        if ( i != 2 ) s ++;
        t --;
    }
    r <<= 1;
    if ( t <= r * 2 ) s += t >> 1; else {
        s += r; t -= r * 2;
        if ( t > 2 ) {
            t -= 2;
            s += t >> 1;
        }
    }
    return s;
}

void init()
{
    cin >> n >> m;
}

void work()
{
    cout << ask( m ) - ask( n - 1 ) << endl;
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
