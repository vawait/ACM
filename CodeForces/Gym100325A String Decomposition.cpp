/*
 * Author:  vawait
 * Created Time:  2015/9/4 13:02:37
 * Problem: Gym100325A String Decomposition
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
int n , f[5100] , pre[5100] , len[5100];
short mx[5100][5100];
char s[5100];

void init()
{
    scanf("%s",s+1);
    n = strlen( s + 1 );
    rep(i,1,n)
        rep(j,1,n) mx[i][j] = s[i] == s[j] ? mx[i-1][j-1] + 1 : 0;
    clr( f , 1 );
    f[0] = 0;
}

void work()
{
    rep(i,1,n) {
        f[i] = f[i-1] + 1;
        len[i] = 1;
        pre[i] = i - 1;
        rep(j,1,i) {
            int m = i - j + 1 , l = j - 1;
            while ( mx[i][l] >= m ) {
                l -= m;
                if ( f[l] + m < f[i] ) {
                    f[i] = f[l] + m;
                    pre[i] = l;
                    len[i] = m;
                }
            }
        }
    }
    cout << f[n] << endl;
    vector < pair < string , int > > g;
    for ( ; n; n = pre[n] ) {
        int l = n - pre[n];
        string str = "";
        rep(i,n-len[n]+1,n) str += s[i];
        g.pb( mp( str , l / len[n] ) );
    }
    red(i,g.size()-1,0) cout << g[i].x << " " << g[i].y << endl;
}

int main()
{
    freopen("decomp.in","r",stdin);
    freopen("decomp.out","w",stdout);
    init();
    work();
    return 0;
}
