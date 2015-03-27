/*
 * Author:  vawait
 * Created Time:  2015/3/27 1:37:40
 * Problem: CodeForces_525E
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
lint n , s , a[40] , fn[40];
int now = 1 , nex = 0 , k;
map < lint , lint > h[2][15] , f[15];
map < lint , lint > :: iterator it;

void init()
{
    rep(i,1,n) cin >> a[i];
    fn[0] = 1;
    rep(i,1,20) fn[i] = fn[i-1] * i;
}

void deal(int l,int r)
{
    rep(i,0,13) h[now][i].clear();
    h[now][0][0] = 1;
    rep(i,l,r) {
        rep(j,0,min(k,13)) h[nex][j] = h[now][j];
        rep(j,0,min(k,13)) {
            for ( it = h[now][j].begin(); it != h[now][j].end(); it ++ ) {
                h[nex][j][it->first+a[i]] += it -> second;
                if ( a[i] < 20 ) h[nex][j+1][it->first+fn[a[i]]] += it -> second;
            }
        }
        swap( nex , now );
    }
}

void work()
{
    lint ans = 0;
    if ( n == 1 ) {
        if ( a[1] <= 20 && fn[a[1]] == s ) ans ++;
        if ( a[1] == s ) ans ++;
    } else {
        deal( n / 2 + 1 , n );
        rep(i,0,min(13,k)) f[i] = h[now][i];
        deal( 1 , n / 2 );
        rep(i,0,min(k,13))
            for ( it = h[now][i].begin(); it != h[now][i].end(); it ++ )
                rep(j,0,min(13,k-i))
                    ans += it -> second * f[j][s-it->first];
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> k >> s ) {
        init();
        work();
    }
    return 0;
}
