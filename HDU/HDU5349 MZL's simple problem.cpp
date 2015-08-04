/*
 * Author:  vawait
 * Created Time:  2015/8/4 12:07:02
 * Problem: HDU5349 MZL's simple problem
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
int n;
multiset < int > h;

void init()
{
    int x , y;
    h.clear();
    rep(i,1,n) {
        scanf("%d",&x);
        if ( x == 1 ) {
            scanf("%d",&y);
            h.insert( y );
        } else if ( x == 2 ) {
            if ( !h.empty() ) h.erase( h.begin() );
        } else {
            int ans = 0;
            if ( !h.empty() ) ans = *( --h.end() );
            printf("%d\n",ans);
        }
    }
}

void work()
{
}

int main()
{
    while ( cin >> n ) {
        init();
        work();
    }
    return 0;
}
