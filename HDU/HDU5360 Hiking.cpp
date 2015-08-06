/*
 * Author:  vawait
 * Created Time:  2015/8/6 14:13:35
 * Problem: HDU5360 Hiking
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
int n , l[maxn] , r[maxn] , use[maxn];
int sum , que[maxn];
pair < int , int > a[maxn];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&l[i]);
    rep(i,1,n) scanf("%d",&r[i]);
    rep(i,1,n) a[i] = mp( l[i] , i );
    rep(i,1,n) use[i] = 0;
    sort( a + 1 , a + n + 1 );
    sum = 0;
}

void work()
{
    priority_queue< pair < int , int > > q;
    int p = 1 , ans = 0;
    for ( ans = 0; 1 ; ans ++ ) {
        while ( p <= n && a[p].x <= ans ) {
            q.push( mp( -r[a[p].y] , a[p].y ) );
            p ++;
        }
        int ok = 0;
        while ( !q.empty() ) {
            int x = -q.top().x , y = q.top().y;
            q.pop();
            if ( x >= ans ) {
                que[++sum] = y;
                use[y] = 1;
                ok = 1;
                break;
            }
        }
        if ( !ok ) break;
    }
    printf("%d\n",ans);
    if ( sum ) {
        printf("%d",que[1]);
        rep(i,2,sum) printf(" %d",que[i]);
        rep(i,1,n) if ( !use[i] ) printf(" %d",i);
        puts("");
    } else {
        printf("1");
        rep(i,2,n) printf(" %d",i);
        puts("");
    }
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
