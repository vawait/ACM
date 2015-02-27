/*
 * Author:  vawait
 * Created Time:  2015/2/27 13:57:37
 * Problem: CodeForces_335B
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
int n , sum = 0 , f[2610][2610] , p[2610][2610][2] , s[100];
char a[101000] , q[10000];

void init()
{
    scanf("%s",a+1);
    n = strlen( a + 1 );
    clr( s , 0 );
    rep(i,1,n) s[a[i]-'a'] ++;
}

void work()
{
    rep(i,0,30) if ( s[i] >= 100 ) {
        rep(j,1,100) printf("%c",i+'a');
        return;
    }
    
    rep(i,1,n) f[i][i] = 1 , p[i][i][0] = i , p[i][i][1] = i - 1;
    rep(l,2,n)
        rep(i,1,n-l+1) {
            int j = i + l - 1;
            if ( a[i] == a[j] ) {
                f[i][j] = ( j - i <= 1 ? 0 : f[i+1][j-1] ) + 2;
                p[i][j][0] = i + 1;
                p[i][j][1] = j - 1;
            } else if ( f[i+1][j] > f[i][j-1] ) {
                f[i][j] = f[i+1][j];
                p[i][j][0] = i + 1;
                p[i][j][1] = j;
            } else {
                f[i][j] = f[i][j-1];
                p[i][j][0] = i;
                p[i][j][1] = j - 1;
            }
        }
    
    int mx = 0 , x , y , v;
    rep(i,1,n)
        rep(j,i,n) if ( f[i][j] > mx ) mx = f[i][j] , x = i , y = j;
    while ( x <= y && f[x][y] ) {
        int l = p[x][y][0] , r = p[x][y][1];
        if ( a[x] == a[y] ) {
            q[++sum] = a[x];
            v = ( x == y );
        }
        x = l , y = r;
    }
    rep(i,1,min(sum,50)) printf("%c",q[i]);
    if ( sum <= 50 && v ) {
        red(i,sum-1,1) printf("%c",q[i]);
    } else {
        red(i,min(sum,50),1) printf("%c",q[i]);
    }
}

int main()
{
    init();
    work();
    return 0;
}
