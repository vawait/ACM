/*
 * Author:  vawait
 * Created Time:  2015/8/15 16:17:22
 * Problem: Gym100203F Find the sequence
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
int Q , a[maxn];
lint n , k , beg , end , sum[maxn];

void add(lint l,lint r,lint s)
{
    ( l += beg ) %= k;
    ( r += beg ) %= k;
    if ( l <= r ) {
        sum[l] += s;
    } else {
        sum[l] += s , sum[0] += s;
    }
    sum[r+1] -= s;
}

void init()
{
    int ty , x , y;
    beg = end = 0;
    clr( sum , 0 );
    scanf("%d",&Q);
    while ( Q -- ) {
        scanf("%d%d",&ty,&x);
        end += x;
        x %= n;
        ( x += n ) %= n;
        if ( ty == 2 && x ) {
            y = x % k;
            if ( y ) {
                add( 0 , k - y - 1 , x / k );
                add( k - y , k - 1 , x / k + 1 );
            } else {
                sum[0] += x / k;
            }
        }
        x %= k;
        ( ( beg -= x ) += k ) %= k;
    }
}

void work()
{
    lint s = n / k;
    rep(i,0,n-1) scanf("%d",&a[i]);
    rep(i,1,n) sum[i] += sum[i-1];
    rep(i,0,n-1) {
        lint x = ( i / k + sum[i%k] ) % s , y = ( i + end ) % k;
        ( x += s ) %= s;
        ( y += k ) %= k;
        printf("%d",a[(x*k+y)%n]);
        if ( i < n - 1 ) printf(" "); else puts("");
    }
}

int main()
{
    while ( cin >> n >> k ) {
        init();
        work();
    }
    return 0;
}
