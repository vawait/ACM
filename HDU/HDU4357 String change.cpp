/*
 * Author:  vawait
 * Created Time:  2015/8/2 13:51:30
 * Problem: HDU4357 String change
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
int n , m , a[100] , b[100] , c[10];
bool vis[26][26][26];
char s[100];

void init()
{
    scanf("%s",s+1);
    n = strlen( s + 1 );
    rep(i,1,n) a[i] = s[i] - 'a';
    scanf("%s",s+1);
    rep(i,1,n) b[i] = s[i] - 'a';
    clr( vis , 0 );
}

void deal(int *a)
{
    rep(i,1,n-2) if ( a[i] ) {
        rep(j,i+1,n) if ( a[j] & 1 ) {
            a[i] += 26 - a[j];
            a[i] %= 26;
            a[j] = 0;
            swap( a[i] , a[j] );
            break;
        }
        swap( a[i+1] , a[i+2] );
        ( a[i+1] += 1 ) %= 26;
        ( a[i+2] += 1 ) %= 26;
        rep(j,i+1,n) if ( a[i] && ( a[j] & 1 ) ) {
            a[i] += 26 - a[j];
            a[i] %= 26;
            a[j] = 0;
            swap( a[i] , a[j] );
            break;
        }
    }
    m = 0;
}

void bfs(int t)
{
    queue< int > q;
    q.push( t );
    while ( !q.empty() ) {
        int x = q.front() , y; q.pop();
        c[1] = x / 1000000 , x %= 1000000;
        c[2] = x / 10000 , x %= 1000;
        c[3] = x / 100 , x %= 100;
        rep(i,1,n)
            rep(j,i+1,n) {
                swap( c[i] , c[j] );
                ( c[i] += 1 ) %= 26;
                ( c[j] += 1 ) %= 26;
                y = c[1] * 1000000 + c[2] * 10000 + c[3] * 100 ;
                if ( !vis[c[1]][c[2]][c[3]] ) q.push( y ) , vis[c[1]][c[2]][c[3]] = 1;
                swap( c[i] , c[j] );
                ( c[i] += 25 ) %= 26;
                ( c[j] += 25 ) %= 26;
            }
    }
}

void work()
{
    deal( a );
    deal( b );
    a[1] = a[n-1] , b[1] = b[n-1];
    a[2] = a[n] , b[2] = b[n];
    c[1] = a[1]  , c[2] = a[2] , c[3] = c[4] = 0;
    if ( n > 3 ) n = 3;
    bfs( a[1] * 1000000 + a[2] * 10000 );
    puts( vis[b[1]][b[2]][0] ? "YES" : "NO" );
}

int main()
{
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
