/*
 * Author:  vawait
 * Created Time:  2015/8/16 12:54:56
 * Problem: Gym100637G #TheDress
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
int n , f[10000];
char s[10000];

int calc()
{
    int t = 0 , len = strlen( s );
    rep(i,3,len-1) {
        if ( s[i-3] == 'b' && s[i-2] == 'l' && s[i-1] == 'u' && s[i] == 'e' )
            t |= 1;
        if ( s[i-3] == 'g' && s[i-2] == 'o' && s[i-1] == 'l' && s[i] == 'd' )
            t |= 4;
    }
    rep(i,4,len-1) {
        if ( s[i-4] == 'b' && s[i-3] == 'l' && s[i-2] == 'a' && s[i-1] == 'c' && s[i] == 'k' )
            t |= 2;
        if ( s[i-4] == 'w' && s[i-3] == 'h' && s[i-2] == 'i' && s[i-1] == 't' && s[i] == 'e' )
            t |= 8;
    }
    return t;
}

void init()
{
    scanf("%d\n",&n);
    rep(i,1,n) {
        gets( s );
        f[i] = calc();
    }
}

void work()
{
    int a = 0 , b = 0 , c = 0;
    double m = n;
    rep(i,1,n) if ( f[i] == 15 ) c ++; else if ( ( f[i] & 3 ) == 3 ) a ++; else if ( ( f[i] & 12 ) == 12 ) b ++; else c ++;
    a *= 100; b *= 100; c *= 100;
    printf("%.9f\n",a/m);
    printf("%.9f\n",b/m);
    printf("%.9f\n",c/m);
}

int main()
{
    init();
    work();
    return 0;
}
