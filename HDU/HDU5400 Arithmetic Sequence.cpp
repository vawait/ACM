/*
 * Author:  vawait
 * Created Time:  2015/8/18 12:18:53
 * Problem: HDU5400 Arithmetic Sequence
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
const int maxn = 101000;
int n , d1 , d2 , a[maxn];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
}

lint calc(lint s)
{
    return s * ( s - 1 ) / 2;
}

void work()
{
    lint ans = n;
    rep(i,1,n-1) if ( a[i+1] - a[i] == d1 ) {
        lint s1 = 1 , s2 = 1;
        while ( i < n && a[i+1] - a[i] == d1 ) {
            i ++ , s1 ++;
        }
        while ( i < n && a[i+1] - a[i] == d2 ) {
            i ++ , s2 ++;
        }
        ans += ( s1 - 1 ) * ( s2 - 1 );
        ans += calc( s1 );
        ans += calc( s2 );
        i --;
    } else if ( a[i+1] - a[i] == d2 ) {
        lint s = 1;
        while ( i < n && a[i+1] - a[i] == d2 ) {
            s ++ ; i ++;
        }
        ans += calc( s );
        i --;
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> d1 >> d2 ) {
        init();
        work();
    }
    return 0;
}
