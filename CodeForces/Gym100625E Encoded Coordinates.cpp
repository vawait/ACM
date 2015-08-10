/*
 * Author:  vawait
 * Created Time:  2015/8/9 14:03:18
 * Problem: Gym100625E Encoded Coordinates
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
lint A , B , C , K , P , N , N2 , x , A2 , B2 , C2 , K2;
int q[19100];

struct nodd
{
    lint a[7][7];
    void cl() { clr( a , 0 ); }
} a , b , c , d;

void init()
{
    cin >> P;
    cin >> A >> B >> C >> K >> N;
    N --;
    cin >> A2 >> B2 >> C2 >> K2 >> N2;
    N2 --;
    cin >> x;
}

void km(nodd &a,nodd &b)
{
    c.cl();
    rep(k,1,5)
        rep(i,1,5)
            rep(j,1,5) ( c.a[i][j] += a.a[i][k] * b.a[k][j] ) %= P;
    a = c;
}

nodd calc(lint n)
{
    a.cl();
    rep(i,1,4) a.a[i][i] = 1;
    b.cl();
    b.a[2][1] = b.a[3][1] = b.a[4][2] = b.a[1][3] = b.a[3][4] = 1;
    b.a[1][2] = b.a[2][3] = K;
    while ( n ) {
        if ( n & 1 ) km( a , b );
        km( b , b );
        n >>= 1;
    }
    return a;
}

void work()
{
    int sum = 0;
    d = calc( N );
    rep(i,0,P-1) {
        a.cl();
        a.a[1][1] = A;
        a.a[1][2] = B;
        a.a[1][3] = C;
        a.a[1][4] = i;
        km( a , d );
        if ( a.a[1][1] == x ) q[++sum] = i;
    }
    A = A2; B = B2; C = C2; K = K2;
    d = calc( N2 );
    
    rep(i,1,sum) {
        a.cl();
        a.a[1][1] = A;
        a.a[1][2] = B;
        a.a[1][3] = C;
        a.a[1][4] = q[i];
        km( a , d );
        q[i] = a.a[1][1];
    }
    
    if ( !sum ) {
        puts("UNKNOWN");
        return;
    }
    rep(i,2,sum) if ( q[i] != q[i-1] ) {
        puts("UNKNOWN");
        return;
    }
    printf("%d\n",q[1]);
}

int main()
{
    int t;
    for ( cin >> t; t; t-- ) {
        init();
        work();
    }
    return 0;
}
