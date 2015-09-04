/*
 * Author:  vawait
 * Created Time:  2015/9/3 13:00:25
 * Problem: Gym100337B Lempel-Ziv Compression
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
int n , f[4100] , pre[4100] , ty[4100];
int sum = 0 , q[4100];
short len[4100][4100];
char s[4100];

void init()
{
    scanf("%s",s+1);
    n = strlen( s + 1 );
    red(i,n,1)
        red(j,n,1) len[i][j] = s[i] == s[j] ? len[i+1][j+1] + 1 : 0;
    clr( f , 1 );
    f[0] = 0;
}

void work()
{
    rep(i,0,n-1) {
        int mx = i + 1 , l , r , x = f[i] + 9 , p;
        if ( x < f[i+1] ) {
            f[i+1] = x;
            pre[i+1] = i;
            ty[i+1] = -1;
        }
        x = f[i] + 25;
        red(k,i,1) {
            l = i + 1;
            r = i - k + 1;
            while ( len[k][l] >= r ) l += r;
            l += len[k][l];
            if ( mx < l ) {
                mx = l;
                p = r;
            }
        }
        rep(j,i+1,mx-1) if ( x < f[j] ) {
            f[j] = x;
            pre[j] = i;
            ty[j] = p;
        }
    }
    
    cout << f[n] << endl;
    while ( n ) {
        if ( ty[n] == -1 ) {
            q[++sum] = -s[n];
        } else {
            q[++sum] = n - pre[n];
            q[++sum] = ty[n];
        }
        n = pre[n];
    }
    red(i,sum,1) if ( q[i] < 0 ) printf("%c",-q[i]); else {
        printf("(%d,%d)",q[i],q[i-1]);
        i --;
    }
}

int main()
{
    freopen("lz.in","r",stdin);
    freopen("lz.out","w",stdout);
    init();
    work();
    return 0;
}
