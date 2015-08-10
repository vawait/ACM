/*
 * Author:  vawait
 * Created Time:  2015/8/8 12:51:19
 * Problem: Gym100589F Count Ways
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
const int maxn = 201000;
const lint mod = 1e9 + 7;
int n , m , k;
lint f[maxn] , fn[maxn] , fw[maxn];
pair < int , int > a[maxn];

lint km(lint a,lint n)
{
    lint s = 1;
    while ( n ) {
        if ( n & 1 ) ( s *= a ) %= mod;
        ( a *= a ) %= mod;
        n >>= 1;
    }
    return s;
}

lint C(int n,int m)
{
    return fn[n+m] * fw[m] % mod * fw[n] % mod;
}

void init()
{
    int x , y;
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,k) {
        scanf("%d%d",&x,&y);
        a[i] = mp( n - x + 1 , m - y + 1 );
    }
    a[++k] = mp( n , m );
    sort( a + 1 , a + k + 1 );
    rep(i,1,k) f[i] = C( a[i].y - 1 , a[i].x - 1 );
}

void work()
{
    rep(i,2,k)
        rep(j,1,i-1) if ( a[j].y <= a[i].y ) {
            f[i] -= f[j] * C( a[i].x - a[j].x , a[i].y - a[j].y );
            f[i] %= mod;
        }
    cout << ( f[k] + mod ) % mod << endl;
}

int main()
{
    int t;
    fn[0] = fw[0] = 1;
    rep(i,1,200000) fn[i] = fn[i-1] * i % mod , fw[i] = km( fn[i] , mod - 2 );
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
