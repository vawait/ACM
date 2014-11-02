/*
 * Author:  Twist Of Fate
 * Created Time:  2014年10月23日 星期四 13时25分36秒
 * File Name: HDU5072.cpp
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
const int maxn = 101000;
const int nn = 100000;
int n , v[maxn] , a[maxn];
lint s[maxn];

void init()
{
    int x;
    clr( v , 0 );
    clr( s , 0 );
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&x) , v[x] = 1;
    rep(i,2,nn) if ( a[i] > 0 ) {
        int ss = 0;
        for ( int j = i; j <= nn; j += i ) ss += v[j];
        if ( !ss ) continue;
        ss --;
        if ( !( a[i] & 1 ) ) ss = - ss;
        for ( int j = i; j <= nn; j += i ) s[j] += ss;
    }
}

void work()
{
    lint ans = (lint)n * ( n - 1 ) * ( n - 2 ) / 3;
    rep(i,2,nn) if ( v[i] ) ans -= s[i] * ( n - 1 - s[i] );
    cout << ans / 2 << endl;
}

int main()
{
    rep(i,2,nn) if ( !a[i] ) 
        for ( int j = i; j <= nn; j += i ) if ( j % sqr( (lint)i ) == 0 ) a[j] = -1000000; else a[j] ++;
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
