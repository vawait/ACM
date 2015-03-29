/*
 * Author:  vawait
 * Created Time:  2015/3/29 19:07:47
 * Problem: CodeForces_329C
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
int n , m , q[101000];
set < pair < int , int > > h;

void init()
{
    int x , y;
    rep(i,1,m) {
        scanf("%d%d",&x,&y);
        h.insert( mp( x , y ) );
        h.insert( mp( y , x ) );
    }
    rep(i,1,n) q[i] = i;
}

void work()
{
    rep(cas,1,3000) {
        int v = 1;
        random_shuffle( q + 1 , q + 1 + n );
        q[n+1] = q[1];
        rep(i,1,m) if ( h.find( mp( q[i] , q[i+1] ) ) != h.end() ) {
            v = 0;
            break;
        }
        if ( v ) {
            rep(i,1,m) printf("%d %d\n",q[i],q[i+1]);
            return;
        }
    }
    puts("-1");
}

int main()
{
    while ( cin >> n >> m ) {
        init();
        work();
    }
    return 0;
}
