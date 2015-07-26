/*
 * Author:  vawait
 * Created Time:  2015/7/26 18:51:35
 * Problem: HDU4253 Two Famous Companies
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
int n , m , ma , mb , num , ans , f[maxn];

struct nodd
{
    int x , y , d;
} a[maxn] , b[maxn];

bool cmp(const nodd &a,const nodd &b)
{
    return a.d < b.d;
}

void init()
{
    int x , y , d , ty;
    ma = mb = 0;
    rep(i,1,m) {
        scanf("%d%d%d%d",&x,&y,&d,&ty);
        x ++; y ++;
        if ( ty ) {
            a[++ma].x = x; a[ma].y = y; a[ma].d = d;
        } else {
            b[++mb].x = x; b[mb].y = y; b[mb].d = d;
        }
    }
    sort( a + 1 , a + ma + 1 , cmp );
    sort( b + 1 , b + mb + 1 , cmp );
    a[ma+1].d = b[mb+1].d = 1e9;
}

int find(int t)
{
    return f[t] == t ? t : f[t] = find( f[t] );
}

int ok(nodd &a)
{
    int p = find( a.x ) , q = find( a.y );
    if ( p == q ) return 0;
    ans += a.d; f[p] = q;
    return 1;
}

int calc(int l)
{
    int sum = 0 , p1 = 1 , p2 = 1;
    rep(i,1,n) f[i] = i;
    ans = 0;
    while ( p1 <= ma || p2 <= mb ) {
        if ( a[p1].d >= b[p2].d + l ) {
            if ( ok( b[p2++] ) ) sum ++ , ans += l;
        } else {
            if ( ok( a[p1++] ) );
        }
    }
    return sum >= num;
}

void work()
{
    int l = -1000 , r = 1000 , k , sum;
    while ( l < r ) {
        k = ( l + r + 1 ) >> 1;
        if ( calc( k ) ) l = k; else r = k - 1;
    }
    calc( l );
    printf("%d\n",ans-num*l);
}

int main()
{
    int t = 0;
    while ( cin >> n >> m >> num ) {
        printf("Case %d: ",++t);
        init();
        work();
    }
    return 0;
}
