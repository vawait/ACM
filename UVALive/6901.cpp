/*
 * Author:  Twist Of Fate
 * Created Time:  2015年03月19日 星期四 14时23分06秒
 * File Name: UVALive_6901
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
int n , x , y , numa , numb , pa[101000] , pb[101000] , t[101000];
char a[101000] , b[101000];

struct bit
{
    int t[101000];
    void add(int x,int y) {
        for ( ; x <= 100000; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
} T;

void init()
{
    scanf("%s%s",a+1,b+1);
    n = strlen( a + 1 );
    numa = numb = 0;
    rep(i,1,n) if ( a[i] == 'a' ) {
        pa[++numa] = i;
    } else {
        pb[++numb] = i;
    }

    x = 0 , y = 0;
    rep(i,1,n) if ( b[i] == 'a' ) t[i] = pa[++x]; else t[i] = pb[++y];

    clr( T.t , 0 );
}

void work()
{
    if ( x != numa || y != numb ) {
        puts("-1");
        return;
    }
    lint sum = 0;
    rep(i,1,n) {
        T.add( t[i] , 1 );
        sum += i - T.sum( t[i] );
    }
    cout << sum << endl;
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
