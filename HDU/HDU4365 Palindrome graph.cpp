/*
 * Author:  vawait
 * Created Time:  2015/8/5 15:25:26
 * Problem: HDU4365 Palindrome graph
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
const int mod = 100000007;
lint f[21000];

void init()
{
    f[0] = 0; f[1] = 1;
    rep(i,2,20000) f[i] = f[i-2] + ( i + 1 ) / 2;
}

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

void work()
{
    int T , n , m , k , x , y;
    while ( cin >> n >> m >> k ) {
        set < pair < int , int > > h;
        rep(i,1,m) {
            scanf("%d%d",&x,&y);
            x ++; y ++;
            pair < int , int > a = mp( x , y );
            rep(j,1,4) {
                x = n + 1 - x;
                swap( x , y );
                a = min( a , min( mp( x , y ) , mp( x , n - y + 1 ) ) );
            }
            h.insert( a );
        }
        printf("%d\n",(int)km(k,f[n]-int(h.size())));
    }
}

int main()
{
    init();
    work();
    return 0;
}
