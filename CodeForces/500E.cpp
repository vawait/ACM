/*
 * Author:  vawait
 * Created Time:  2014/12/31 0:30:43
 * Problem: CodeForces_500E
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
const int maxn = 201000;
int n , m , sum , Right[maxn] , rightid[maxn] , next[maxn] , nextid[maxn] , ans[maxn] , q[maxn] , f[maxn];
pair < int , int > a[201000];
vector < pair < int , int > > ask[maxn];

void init()
{
    int x , y;
    rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y) , ask[i].clear();
    scanf("%d",&m);
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        ask[x].pb( mp( y , i ) );
    }
    sum = 0;
}

void deal(int now,int nex,int id)
{
    int sum = 0;
    while ( rightid[now] < nex ) {
        if ( next[now] <= nex ) {
            sum += f[now];
            now = next[now];
        } else {
            sum += a[nextid[now]].x - Right[now];
            now = nextid[now];
        }
    }
    ans[id] = sum;
}

void work()
{
    red(i,n,1) {
        rightid[i] = i;
        Right[i] = a[i].x + a[i].y;
        while ( sum && Right[i] >= a[q[sum]].x ) {
            rightid[i] = rightid[q[sum]];
            Right[i] = max( Right[i] , Right[q[sum]] );
            sum --;
        }
        nextid[i] = q[sum];
        q[++sum] = i;
        f[i] = 0;
        red(j,sum-1,max(sum-300,1)) {
            f[i] += a[q[j]].x - Right[q[j+1]];
            next[i] = q[j];
        }
        red(j,ask[i].size()-1,0) deal( i , ask[i][j].x , ask[i][j].y );
    }
    rep(i,1,m) printf("%d\n",ans[i]);
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
