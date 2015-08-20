/*
 * Author:  vawait
 * Created Time:  2015/8/19 12:49:35
 * Problem: Gym100418B Sum of sequences
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
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
int n , m;
pair < lint , lint > a[maxn] , b[maxn];
lint sum1 = 0 , sum2 = 0 , j1 = 0 , j2 = 0 , num1 = 0 , num2 = 0 , jb1 = 0 , jb2 = 0;

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%I64d",&a[i].x) , a[i].y = i;
    rep(i,1,m) scanf("%I64d",&b[i].x) , b[i].y = i;
    sort( a + 1 , a + n + 1 );
    sort( b + 1 , b + m + 1 );
    rep(i,1,m) j2 += i , sum2 += b[i].x , num2 ++ , jb2 += b[i].x * b[i].y;
}

void work()
{
    lint ans = 0 , p = 1;
    rep(i,1,n) {
        while ( p <= m && a[i].x >= b[p].x ) {
            j1 += b[p].y , sum1 += b[p].x;
            j2 -= b[p].y , sum2 -= b[p].x;
            jb2 -= b[p].x * b[p].y , jb1 += b[p].x * b[p].y;
            num1 ++ , num2 --;
            p ++;
        }
        ans += num1 * a[i].y * a[i].x - sum1 * a[i].y - j1 * a[i].x + jb1;
        ans += sum2 * a[i].y - num2 * a[i].x * a[i].y - jb2 + j2 * a[i].x;
    }
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
