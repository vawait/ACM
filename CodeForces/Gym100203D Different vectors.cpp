/*
 * Author:  vawait
 * Created Time:  2015/8/15 14:47:11
 * Problem: Gym100203D Different vectors
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
typedef unsigned long long lint;
typedef pair < int , int > pp;
lint mm = 10003;
int n , m , ans ;
lint b[10000];
pp a[1000];
set < pair < lint , lint > > h;

void init()
{
    ans = 0;
    h.clear();
    scanf("%d%d",&n,&m);
    
    lint mod = 1;
    rep(i,1,m) mod *= mm;
    while ( n -- ) {
        rep(i,1,m) scanf("%d",&a[i].x) , a[i].y = i;
        sort( a + 1 , a + m + 1 );
        a[0].x = a[1].x - 1;
        int y;
        rep(i,1,m) if ( a[i].x != a[i-1].x ) {
            b[y=a[i].y] = m;
        } else {
            b[a[i].y] = a[i].y - a[i-1].y;
            b[y] = m - ( a[i].y - y );
        }
        rep(i,m+1,m+m) b[i] = b[i-m];
        b[0] = 0;
        rep(i,1,m+m) b[i] = b[i-1] * mm + b[i];
        
        red(i,m+m,m) b[i] -= b[i-m] * mod;
        lint mi = b[m+1] , mx = b[m+1];
        rep(i,m+1,m+m) mi = min( mi , b[i] ) , mx = max( mx , b[i] );
        if ( h.find( mp( mi , mx ) ) == h.end() ) {
            ans ++;
            h.insert( mp( mi , mx ) );
        }
    }
}

void work()
{
    printf("%d\n",ans);
}

int main()
{
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
