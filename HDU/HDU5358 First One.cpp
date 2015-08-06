/*
 * Author:  vawait
 * Created Time:  2015/8/6 16:34:17
 * Problem: HDU5358 First One
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
int n , p[40] , now = 1 , nex = 0;
lint a[maxn] , f[40];
char c;

void scan(int &x){
    while(c=getchar(),c<'0'||c>'9');x=c-'0';
    while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';
}

void init()
{
    int x;
    scanf("%d",&n);
    a[0] = 0;
    rep(i,1,n) scan(x) , a[i] = a[i-1] + x;
    rep(i,1,35) f[i] = 1LL << i;
    f[0] = 0;
    rep(i,0,35) p[i] = 1;
}

void work()
{
    lint ans = 0;
    rep(i,1,n) {
        rep(j,0,35) {
            while ( p[j] < i || p[j] < n && a[p[j]] - a[i-1] < f[j] ) p[j] ++;
        }
        int l = 0 , r = 0;;
        rep(j,0,35) if ( a[i] - a[i-1] >= f[j] ) l = j;
        rep(j,0,35) if ( a[n] - a[i-1] >= f[j] ) r = j;
        p[r+1] = n + 1;
        rep(j,l,r) {
            ans += lint( j + 1 ) * lint( p[j] + i + i + p[j+1] - 1 ) * lint( p[j+1] - p[j] ) / 2;
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
