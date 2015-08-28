/*
 * Author:  vawait
 * Created Time:  2015/8/27 13:47:25
 * Problem: Gym100338E Numbers
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
lint a[80] , b[80];
lint n , m;

void init()
{
    rep(i,1,70) b[i] = n % 10 , a[i] = n , n /= 10;
}

bool ok(lint n)
{
    lint l , r;
    red(i,70,1) if ( a[i] >= n ) {
        l = r = n;
        if ( a[i] == n ) {
            red(j,i-1,1) l *= 10 , r = r * 10 + b[j];
        } else {
            red(j,i-1,1) l *= 10 , r = r * 10 + 9;
        }
        if ( r >= m && r / m > ( l - 1 ) / m ) return 1;
    }
    return 0;
}

void work()
{
    lint n = 0 , zero = 1;
    red(p,70,1) {
        n *= 10;
        rep(i,0+zero,9) if ( ok( n + i ) ) {
            n += i;
            printf("%d",i);
            break;
        }
        zero = 0;
        if ( n % m == 0 ) break;
    }
    puts("");
}

int main()
{
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    while ( cin >> n >> m && n ) {
        init();
        work();
    }
    return 0;
}
