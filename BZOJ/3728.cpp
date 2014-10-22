/*
 * Author:  vawait
 * Created Time:  2014/10/16 18:38:35
 * File Name: BZOJ3728.cpp
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
const int maxn = 501000;
int n , k , p[maxn];
priority_queue < int > q;
multiset < int > s;
multiset < int >::iterator it;

void init()
{
    int x;
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&p[i]);
    rep(i,1,n) scanf("%d",&x) , s.insert( -x );
    sort( p + 1 , p + n + 1 );
}

void work()
{
    lint ans = 0;
    rep(i,1,n) {
        it = s.lower_bound( -p[i] );
        if ( it == s.end() ) continue;
        q.push( p[i] + *it );
        s.erase( it );
        ans += p[i];
    }
    for ( it = s.begin(); it != s.end(); it ++ ) {
        ans -= *it;
        k --;
    }
    if ( k < 0 ) {
        puts("NIE");
        return;
    }
    rep(i,1,k) {
        ans -= q.top();
        q.pop();
    }
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
