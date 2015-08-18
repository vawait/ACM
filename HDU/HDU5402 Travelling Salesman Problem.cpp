/*
 * Author:  vawait
 * Created Time:  2015/8/18 14:41:14
 * Problem: HDU5402 Travelling Salesman Problem
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
int sa , sum , n , m , s , a[110][110] ;
bool vis[110][110];
pair < int , pair < int , int > > q[100000];
char ans[20100];

void init()
{
    clr( a , 0 );
    sum = 0;
    rep(i,1,n)
        rep(j,1,m) scanf("%d",&a[i][j]) , sum += a[i][j];
    s = 0;
    rep(i,1,n)
        rep(j,1,m) {
            q[++s] = mp( a[i][j] , mp( i , j ) );
        }
    sort( q + 1 , q + s + 1 );
}

void pri1()
{
    printf("%d\n",sum);
    if ( n & 1 ) {
        rep(i,1,n) {
            rep(j,2,m) printf("%c",(i&1)?'R':'L'); 
            if ( i != n ) printf("D");
        }
        puts("");
    } else {
        rep(i,1,m) {
            rep(j,2,n) printf("%c",(i&1)?'D':'U');
            if ( i != m ) printf("R");
        }
        puts("");
    }
}

void do1(int &ss)
{
}

bool ok(int sx,int sy)
{
    int x = 1 , y = 1 , ss = a[1][1];
    clr( vis , 0 );
    vis[sx][sy] = 1;
    sa = 0;
    if ( ( sx & 1 ) == 0 ) {
        while ( x < sx - 1 ) {
            rep(i,2,m) ss += a[x][i] , ans[++sa] = 'R';
            x ++;
            ss += a[x][m]; ans[++sa] = 'D';
            red(i,m-1,1) ss += a[x][i] , ans[++sa] = 'L';
            x ++; 
            ss += a[x][1]; ans[++sa] = 'D';
            if ( vis[x][1] ) return 0;
        }
        rep(i,1,m) {
            int xx = ( x & 1 ) ? x + 1 : x - 1;
            if ( !vis[xx][i] && !vis[xx][i] ) {
                ans[++sa] = ( xx < x ) ? 'U' : 'D'; 
                ss += a[xx][i];
                ss += a[xx][i+1];
                ans[++sa] = 'R';
                x = xx;
            } else if ( !vis[x][i+1] ) {
                ss += a[x][i+1];
                ans[++sa] = 'R';
            }
        }
        x ++;
        ss += a[x][m];
        ans[sa] = 'D';
        while ( x < n ) {
            red(i,m-1,1) ss += a[x][i] , ans[++sa] = 'L';
            x ++; 
            ss += a[x][1]; ans[++sa] = 'D';
            rep(i,2,m) ss += a[x][i] , ans[++sa] = 'R';
            x ++;
            ss += a[x][m]; ans[++sa] = 'D';
        }
    } else {
            while ( y < sy - 1 ) {
                int j = y;
                rep(i,2,n) {
                    ss += a[i][j];
                    ans[++sa] = 'D';
                }
                j ++;
                ans[++sa] = 'R';
                ss += a[n][j];
                
                red(i,n-1,1) {
                    ss += a[i][j];
                    ans[++sa] = 'U';
                }
                j ++;
                ans[++sa] = 'R';
                ss += a[1][j];
                y = j;
            }
            if ( vis[1][y] ) return 0;
            rep(i,1,n) {
                int yy = ( y & 1 ) ? y + 1 : y - 1;
                if ( !vis[i][yy] && !vis[i+1][yy] ) {
                    ans[++sa] = ( yy < y ) ? 'L' : 'R'; 
                    ss += a[i][yy];
                    ss += a[i+1][yy];
                    ans[++sa] = 'D';
                    y = yy;
                } else if ( !vis[i+1][y] ) {
                    ss += a[i+1][y];
                    ans[++sa] = 'D';
                }
            }
            ans[sa] = 'R';
            y ++;
            ss += a[n][y];
            for ( int j = y; j <= m ; ) {
                red(i,n-1,1) {
                    ss += a[i][j];
                    ans[++sa] = 'U';
                }
                j ++;
                ans[++sa] = 'R';
                ss += a[1][j];
                rep(i,2,n) {
                    ss += a[i][j];
                    ans[++sa] = 'D';
                }
                j ++;
                ans[++sa] = 'R';
                ss += a[n][j];
            }
    }
    return ss == sum - a[sx][sy];
}

void work()
{
    if ( ( n & 1 ) || ( m & 1 ) ) {
        pri1();
        return;
    }
    rep(i,1,s) {
        int x = q[i].y.x , y = q[i].y.y;
        if ( x == 1 && y == 1 ) continue;
        if ( x == n && y == m ) continue;
        if ( ( x & 1 ) == ( y & 1 ) ) continue;
        if ( ok( x , y ) ) {
            printf("%d\n",sum-a[x][y]);
            rep(j,1,sa-1) printf("%c",ans[j]);
            puts("");
            return;
        }
    }
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
