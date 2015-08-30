/*
 * Author:  vawait
 * Created Time:  2015/8/30 15:29:34
 * Problem: Gym100342F Move to Front
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
int n , a[maxn] , b[maxn] , pre[maxn] , use[maxn];
vector < int > g;

struct bit
{
    int t[101000];
    void add(int x,int y) {
        for ( ; x <= 100010; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
} T1 , T2;


void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&b[i]) , g.pb( b[i] );
    sort( g.begin() , g.end() );
    g.resize( unique( g.begin() , g.end() ) - g.begin() );
    rep(i,1,n) a[i] = lower_bound( g.begin() , g.end() , b[i] ) - g.begin() + 1;
}

void work()
{
    int x;
    rep(i,1,n) {
        x = a[i];
        if ( !pre[x] ) {
            printf("%d ",b[i]+T1.sum(100010)-T1.sum(a[i]));
            use[x] = 1;
            T1.add( x , 1 );
        } else {
            printf("%d ",1+T2.sum(i)-T2.sum(pre[x]));
            T2.add( pre[x] , -1 );
        }
        pre[x] = i;
        T2.add( pre[x] , 1 );
    }
}

int main()
{
    freopen("mtf.in","r",stdin);
    freopen("mtf.out","w",stdout);
    init();
    work();
    return 0;
}
