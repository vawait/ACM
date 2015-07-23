/*
 * Author:  vawait
 * Created Time:  2015/7/22 14:49:56
 * Problem: HDU4125 Moles
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
const int maxn = 600010;
int n , f[maxn][2] , root , p[8000] , que[maxn];
int ans , j , len;
char b[8000];
set < int > h;
set < int > :: iterator it;

void dfs()
{
    int t = 1 , y;
    que[t] = root;
    while ( t ) {
        y = que[t];
        
        char c = ( y & 1 ) ? '1' : '0';
        while ( j && b[j+1] != c ) j = p[j];
        if ( b[j+1] == c ) j++;
        if ( j >= len ) ans ++;
        
        int v = 1;
        rep(i,0,1) if ( f[y][i] ) {
            que[++t] = f[y][i];
            f[y][i] = 0;
            v = 0;
            break;
        }
        t -= v;
    }
    /*
    a[++sum] = ( t & 1 ) ? '1' : '0';
    if ( f[t][0] ) dfs( f[t][0] ) , a[++sum] = ( t & 1 ) ? '1' : '0';
    if ( f[t][1] ) dfs( f[t][1] ) , a[++sum] = ( t & 1 ) ? '1' : '0';
    */
}

void init()
{
    int x;
    scanf("%d%d",&n,&root);
    rep(i,1,n) f[i][0] = f[i][1] = 0;
    h.insert( root );
    rep(i,2,n) {
        scanf("%d",&x);
        h.insert( x );
        it = ++ h.find( x );
        if ( it != h.end() && !f[*it][0] ) {
            f[*it][0] = x;
        } else {
            it = -- h.find( x );
            f[*it][1] = x;
        }
    }
    h.clear();
    scanf("%s",b+1);
}

void work()
{
    ans = 0 , j = 0 , len = strlen( b + 1 );
    p[1] = 0;
    rep(i,2,len) {
        while ( j && b[j+1] != b[i] ) j = p[j];
        if ( b[j+1] == b[i] ) j++;
        p[i] = j;
    }
    j = 0;
    dfs();
    printf("%d\n",ans);
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
