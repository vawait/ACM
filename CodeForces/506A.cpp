/*
 * Author:  vawait
 * Created Time:  2015/1/18 20:36:06
 * Problem: CodeForces_506A
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
int n , d , a[31000] , f[30010][610];

void init()
{
    int x;
    clr( a , 0 );
    rep(i,1,n) scanf("%d",&x) , a[x] ++;
    d -= 300;
}

void work()
{
    int x;
    red(i,30000,0)
        rep(j,1,600) {
            f[i][j] = a[i];
            x = 0;
            rep(k,j-1,j+1) if ( k + d > 0 && k + d + i <= 30000 ) {
                x = max( x , f[k+d+i][k] );
            }
            f[i][j] += x;
        }
    cout << f[d+300][300] << endl;
}

int main()
{
    while ( cin >> n >> d ) {
        init();
        work();
    }
    return 0;
}
