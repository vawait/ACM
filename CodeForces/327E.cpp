/*
 * Author:  vawait
 * Created Time:  2015/3/29 18:42:01
 * Problem: CodeForces_327E
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
const int mm = 1000000007;
int n , m , mx , a[100] , b[100] , f[1<<24];
lint sum[1<<24];

void init()
{
    rep(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&m);
    rep(i,1,m) scanf("%d",&b[i]);
    sort( b + 1 , b + m + 1 );
    clr( f , 0 );
    f[0] = 1;
    mx = ( 1 << n ) - 1;
}

void work()
{
    rep(i,1,mx) {
        int s = 0;
        rep(j,0,n-1) if ( ( i >> j ) & 1 ) {
            s += f[i^(1<<j)];
            if ( s >= mm ) s -= mm;
        }
        rep(j,0,n-1) if ( ( i >> j ) & 1 ) {
            sum[i] = a[j+1] + sum[i^(1<<j)];
            break;
        }
        f[i] = s;
        rep(j,1,m) if ( sum[i] == b[j] ) f[i] = 0;
    }
    cout << f[mx] << endl;
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
