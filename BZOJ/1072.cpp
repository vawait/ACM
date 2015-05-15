/*
 * Author:  vawait
 * Created Time:  2015/5/15 14:07:19
 * Problem: BZOJ_1072
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
#define two( x ) ( 1 << ( x ) )
typedef long long lint;
int n , m , d , a[20];
int f[1<<10][1001];
char s[20];

void init()
{
    scanf("%s%d",s,&d);
    n = strlen( s ) - 1;
    m = ( 1 << ( n + 1 ) ) - 1;
    rep(i,0,n) a[i] = s[i] - '0';
    sort( a , a + n + 1 );
    clr( f , 0 );
    f[0][0] = 1;
}

void work()
{
    rep(i,0,m) {
        rep(j,0,n) if ( ( i & two( j ) ) == 0 ) {
            if ( j && a[j] == a[j-1] && ( i & two( j - 1 ) ) == 0 ) continue;
            rep(k,0,d-1) {
                f[i|two(j)][(k*10+a[j])%d] += f[i][k];
            }
        }
    }
    cout << f[m][0] << endl;
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
