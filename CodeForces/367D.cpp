/*
 * Author:  vawait
 * Created Time:  2015/3/22 13:48:18
 * Problem: CodeForces_367D
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
int n , m , d , v[1<<21] , a[101000] , s[100];

void init()
{
    int x , y;
    clr( v , 0 );
    clr( s , 0 );
    rep(i,1,m) {
        scanf("%d",&x);
        while ( x -- ) scanf("%d",&y) , a[y] = i;
    }
}

void work()
{
    int ans = m;
    rep(i,1,n) {
        if ( i > d ) s[a[i-d]] --;
        s[a[i]] ++;
        if ( i >= d ) {
            int x = 0;
            rep(j,1,m) if ( !s[j] ) x |= ( 1 << ( j - 1 ) );
            v[x] = 1;
        }
    }
    red(i,(1<<m)-1,0) if ( !v[i] ) {
        ans = min( ans ,  __builtin_popcount(i) );
    } else {
        rep(j,0,m-1) if ( i >> j & 1 ) v[i^(1<<j)] = 1;
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m >> d ) {
        init();
        work();
    }
    return 0;
}
