/*
 * Author:  vawait
 * Created Time:  2015/5/20 13:30:25
 * Problem: BZOJ_3152
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
const int maxn = 2e6 + 10;
int n , a[maxn];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
}

void work()
{
    if ( n == 1 ) {
        puts("0");
        return;
    }
    
    int sum = a[1] - 1 , ans = 1;
    priority_queue < int > q;
    rep(i,2,n) {
        if ( sum ) {
            sum --;
        } else {
            ans ++;
            if ( q.empty() || q.top() < 2 ) {
                ans = -1;
                break;
            } else {
                sum = q.top() - 2;
                q.pop();
            }
        }
        q.push( a[i] );
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
