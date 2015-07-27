/*
 * Author:  vawait
 * Created Time:  2015/7/27 14:58:36
 * Problem: HDU4288 Coder
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
int n , m , id[maxn] , ty[maxn];
vector < int > g;
char c[maxn][4];

struct nodd
{
    int sum , a[500];
    lint ans[5];
    void cl() {
        clr( ans , 0 );
        sum = 0;
    }
    void calc() {
        clr( ans , 0 );
        rep(i,0,sum-1) ans[i%5] += a[i];
    }
    void add(int t) {
        a[sum++] = t;
        red(i,sum-1,1) if ( a[i] < a[i-1] ) swap( a[i] , a[i-1] );
        calc();
    }
    void del(int t) {
        rep(i,0,sum-1) if ( a[i] == t ) {
            rep(j,i,sum-2) a[j] = a[j+1];
            sum --;
            calc();
            return;
        }
    }
} a[500];

void init()
{
    g.clear();
    m = 0;
    rep(i,1,n) {
        scanf("%s",c[i]);
        if ( c[i][0] != 's' ) {
            m ++;
            scanf("%d",&ty[i]) , g.pb( ty[i] );
        }
    }
    sort( g.begin() , g.end() );
    m = (int)sqrt( m ) + 10;
    rep(i,0,m+10) a[i].cl();
}

void calc()
{
    lint ans = 0;
    int p = 1;
    rep(i,0,m+10) if ( a[i].sum ) {
        rep(j,0,4) if ( ( p + j ) % 5 == 3 ) ans += a[i].ans[j];
        p += a[i].sum;
    }
    printf("%I64d\n",ans);
}

void work()
{
    rep(i,1,n) {
        if ( c[i][0] == 'a' ) {
            int k = lower_bound( g.begin() , g.end() , ty[i] ) - g.begin();
            a[k/m].add( ty[i] );
        } else if ( c[i][0] == 'd' ) {
            int k = lower_bound( g.begin() , g.end() , ty[i] ) - g.begin();
            a[k/m].del( ty[i] );
        } else {
            calc();
        }
    }
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
