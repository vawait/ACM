/*
 * Author:  vawait
 * Created Time:  2015/3/18 14:44:00
 * Problem: CodeForces_528A
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
int w , h , n;

void init()
{
}

void work()
{
    char c[10];
    int x , l , r;
    multiset < pair < int , int > > H , V , *p1;
    multiset < pair < int , int > > :: iterator it1;
    multiset < int > hlen , vlen , *p2;
    multiset < int > :: iterator it2;
    H.insert( mp( h , 0 ) );
    V.insert( mp( w , 0 ) );
    hlen.insert( h );
    vlen.insert( w );
    while ( n -- ) {
        scanf("%s%d",c,&x);
        if ( c[0] == 'H' ) {
            p1 = &H , p2 = &hlen;
        } else {
            p1 = &V , p2 = &vlen;
        }
        it1 = p1 -> lower_bound( mp( x , x ) );
        l = it1 -> y , r = it1 -> x;
        if ( l < x && r > x ) {
            p2->erase( p2 -> find( r - l ) );
            p2->insert( x - l );
            p2->insert( r - x );
            p1->erase( it1 );
            p1->insert( mp( x , l ) );
            p1->insert( mp( r , x ) );
        }
        l = *( --( it2 = hlen.end() ) );
        r = *( --( it2 = vlen.end() ) );
        printf("%I64d\n",(lint)l*r);
    }
}

int main()
{
    while ( cin >> w >> h >> n ) {
        init();
        work();
    }
    return 0;
}
