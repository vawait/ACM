/*
 * Author:  vawait
 * Created Time:  2015/7/13 12:50:57
 * Problem: BZOJ2563 阿狸和桃子的游戏
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
const int maxn = 10000;
int n , m;
lint sum[maxn];

void init()
{
    int x , y , d;
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&x) , sum[i] = x * 2;
    rep(i,1,m) {
        scanf("%d%d%d",&x,&y,&d);
        sum[x] += d; sum[y] += d;
    }
}

void work()
{
    lint ans = 0;
    sort( sum + 1 , sum + n + 1 );
    rep(i,1,n) if ( i & 1 ) ans -= sum[i]; else ans += sum[i];
    cout << ans / 2 << endl;
}

int main()
{
    init();
    work();
    return 0;
}
