/*
 * Author:  vawait
 * Created Time:  2014/11/4 14:41:52
 * Problem: POJ_3167
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
int n , m , k , f1[maxn] , f2[maxn] , p[maxn] , a[maxn] , b[maxn];
int s , sum[30] , q[maxn];

int ask(int r)
{
    int s = 0;
    rep(i,0,r-1) s += sum[i];
    return s;
}

void init()
{
    rep(i,1,n) scanf("%d",&b[i]);
    rep(i,1,m) scanf("%d",&a[i]);
    s = 0;
    clr( sum , 0 );
    rep(i,1,m) f1[i] = ask( a[i] ) , f2[i] = sum[a[i]] ++;
    f1[m+1] = -1;
}

void work()
{
    int j = 0 , l , r;
    p[1] = 0;
    clr( sum , 0 );
    rep(i,2,m) {
        while ( j && ( f2[j+1] != sum[a[i]] || f1[j+1] != ask( a[i] ) ) ) {
            l = i - j; r = i - p[j] - 1;
            rep(k,l,r) sum[a[k]] --;
            j = p[j];
        }
        if ( f2[j+1] == sum[a[i]] && f1[j+1] == ask( a[i] ) ) j ++ , sum[a[i]] ++;
        p[i] = j;
    }
    j = 0;
    clr( sum , 0 );
    rep(i,1,n) {
        while ( j && ( f2[j+1] != sum[b[i]] || f1[j+1] != ask( b[i] ) ) ) {
            l = i - j; r = i - p[j] - 1;
            rep(k,l,r) sum[b[k]] --;
            j = p[j];
        }
        if ( f2[j+1] == sum[b[i]] && f1[j+1] == ask( b[i] ) ) j ++ , sum[b[i]] ++;
        if ( j == m ) q[++s] = i - m + 1;
    }
    printf("%d\n",s);
    rep(i,1,s) printf("%d\n",q[i]);
}

int main()
{
    while ( cin >> n >> m >> k ) {
        init();
        work();
    }
    return 0;
}
