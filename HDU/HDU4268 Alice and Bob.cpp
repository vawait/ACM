/*
 * Author:  vawait
 * Created Time:  2015/7/26 13:24:00
 * Problem: HDU4268 Alice and Bob
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
int n;
pair < int , int > a[maxn] , b[maxn];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    rep(i,1,n) scanf("%d%d",&b[i].x,&b[i].y);
    sort( a + 1 , a + n + 1 );
    sort( b + 1 , b + n + 1 );
}

void work()
{
    int p = n , ans = 0;
    multiset < int > q;
    multiset < int >::iterator it;
    red(i,n,1) {
        while ( p && a[p].x >= b[i].x ) q.insert( a[p--].y );
        it = q.lower_bound( b[i].y );
        if ( it != q.end() ) {
            ans ++;
            q.erase( it );
        }
    }
    cout << ans << endl;
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
