/*
 * Author:  vawait
 * Created Time:  2015/8/6 15:48:55
 * Problem: HDU5353 Average
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
int n , sum , a[maxn] , b[maxn] , y[maxn];
pair < int , int > ans[maxn];
vector < int > g[maxn];
lint avg;

void init()
{
    scanf("%d",&n);
    avg = 0;
    rep(i,1,n) {
        scanf("%d",&a[i]);
        avg += a[i];
    }
}

int ok(int p,int k)
{
    int y;
    rep(i,1,n) a[i] = b[i];
    sum = 0;
    rep(i,1,n) {
        y = p + k;
        if ( y > n ) y = 1;
        if ( y < 1 ) y = n;
        if ( a[p] > 0 ) {
            ans[++sum] = mp( p , y );
            a[p] --; a[y] ++;
        } else if ( a[p] < 0 ) {
            ans[++sum] = mp( y , p );
            a[p] ++; a[y] --;
        }
        p = y;
    }
    rep(i,1,n) if ( a[i] ) return 0;
    rep(i,2,sum) if ( ans[i] == ans[i-1] ) return 0;
    return 1;
}

void pri()
{
    queue < int > q;
    rep(i,1,n) g[i].clear() , a[i] = 0;
    rep(i,1,sum) g[ans[i].x].pb( ans[i].y ) , a[ans[i].y] ++;
    puts("YES");
    printf("%d\n",sum);
    rep(i,1,n) if ( !a[i] ) q.push( i );
    int x , y;
    while ( !q.empty() ) {
        x = q.front(); q.pop();
        red(i,g[x].size()-1,0) {
            y = g[x][i];
            printf("%d %d\n",x,y);
            a[y] --;
            if ( !a[y] ) q.push( y );
        }
    }
}

void work()
{
    if ( avg % n ) {
        puts("NO");
        return;
    }
    avg /= n;
    int p = 0;
    rep(i,1,n) {
        a[i] -= avg;
        b[i] = a[i];
        if ( a[i] > 0 ) p = i;
    }
    if ( !p ) {
        puts("YES");
        puts("0");
        return;
    }
    if ( ok( p , 1 ) ) {
        pri();
    } else if ( ok( p , -1 ) ) {
        pri();
    } else puts("NO");
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
