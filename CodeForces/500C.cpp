/*
 * Author:  vawait
 * Created Time:  2014/12/30 23:25:19
 * Problem: CodeForces_500C
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
int n , m , s , w[2000] , b[2000] , q[2000] , v[2000];

void init()
{
    rep(i,1,n) scanf("%d",&w[i]);
    rep(i,1,m) scanf("%d",&b[i]);
    clr( v , 0 ); 
    s = 0;
    rep(i,1,m)  {
        if ( !v[b[i]] ) q[++s] = b[i]; 
        v[b[i]] = 1;
    }
}

void work()
{
    int ans = 0;
    rep(k,1,m) {
        int sum = 0;
        rep(i,1,s) if ( q[i] == b[k] ) {
            red(j,i,2) q[j] = q[j-1];
            q[1] = b[k];
            break;
        } else sum += w[q[i]];
        ans += sum;
    }
    cout << ans << endl;
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
