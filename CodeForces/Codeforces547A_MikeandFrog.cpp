/*
 * Author:  vawait
 * Created Time:  2015/5/27 0:29:03
 * Problem: Codeforces547A Mike and Frog
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
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
lint m , h1 , a1 , x1 , y1 , h2 , a2 , x2 , y2;

void init()
{
    cin >> h1 >> a1 >> x1 >> y1;
    cin >> h2 >> a2 >> x2 >> y2;
}

void work()
{
    lint sum1 = 0 , sum2 = 0;
    lint g1 = 0 , g2 = 0;
    red(i,2e6,0) {
        if ( h1 == a1 ) break;
        h1 = ( x1 * h1 + y1 ) % m;
        sum1 ++;
    }
    red(i,2e6,0) {
        if ( h2 == a2 ) break;
        h2 = ( h2 * x2 + y2 ) % m;
        sum2 ++;
    }
    if ( h1 != a1 || h2 != a2 ) {
        puts("-1");
        return;
    }
    red(i,2e6,0) {
        h1 = ( x1 * h1 + y1 ) % m;
        g1 ++;
        if ( h1 == a1 ) break;
    }
    red(i,2e6,0) {
        h2 = ( h2 * x2 + y2 ) % m;
        g2 ++;
        if ( h2 == a2 ) break;
    }
    if ( sum1 == sum2 ) {
        cout << sum1 << endl;
        return;
    }
    if ( h1 == a1 && sum2 >= sum1 && sum2 % g1 == sum1 % g1 ) {
        cout << sum2 << endl;
        return;
    }
    if ( h2 == a2 && sum1 >= sum2 && sum1 % g2 == sum2 % g2 ) {
        cout << sum1 << endl;
        return;
    }
    if ( h1 != a1 || h2 != a2 ) {
        puts("-1");
        return;
    }
    red(i,2e6,0) {
        if ( sum1 >= sum2 && sum1 % g2 == sum2 % g2 ) {
            cout << sum1 << endl;
            return;
        }
        sum1 += g1;
    }
    puts("-1");
}

int main()
{
    while ( cin >> m ) {
        init();
        work();
    }
    return 0;
}
