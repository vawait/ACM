/*
 * Author:  vawait
 * Created Time:  2015/3/22 20:11:26
 * Problem: test.cpp
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
const int maxn = 21000;
int n , m , t , ans[maxn] , sum[maxn];
pair < int , int > a[maxn];

void init()
{
    int x , y , z;
    rep(i,1,n) {
        scanf("%d%*c%d%*c%d",&x,&y,&z);
        a[i] = mp( x * 3600 + y * 60 + z , i );
    }
    sort( a + 1 , a + n + 1 );
    clr( sum , 0 );
}

void work()
{
    int p = 1 , ok = 0 , x , num = 0 , s = 0;
    rep(i,1,n) {
        while ( a[i].x - a[p].x > t ) p ++;
        if ( i - p + 1 >= m ) ok = 1;
    }
    if ( !ok ) {
        puts("No solution");
        return ;
    }
    p = 1;
    
    rep(i,1,n) {
        while ( a[i].x - a[p].x >= t ) {
            if ( !( -- sum[ans[a[p].y]] ) ) s --;
            p ++;
        }
        if ( s < m ) x = ++num; else x = ans[a[i-1].y];
        ans[a[i].y] = x;
        if ( !( sum[x]++ ) ) s ++;
    }
    
    printf("%d\n",num);
    rep(i,1,n) printf("%d\n",ans[i]);
}

int main()
{
    while ( cin >> n >> m >> t ) {
        init();
        work();
    }
    return 0;
}
