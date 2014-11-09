/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月09日 星期日 15时29分08秒
 * File Name: HDU_4025
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define db pop_back
typedef long long lint;
int n , m , a[40][40] , sum1 , sum2 , v[6]; 
lint S1[200000] , S2[200000] , *s1 = S1 , *s2 = S2;
lint Q1[200000] , Q2[200000] , Q[200000] , *q1 = Q1 , *q2 = Q2 , *q = Q;

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n)
        rep(j,1,m) scanf("%d",&a[i][j]);
    sum1 = sum2 = 1;
    q1[1] = q2[1] = 0;
    clr( v , 0 );
}

void deal(int l,int r,lint *&q,lint *&q1,int &sum,lint *&s)
{
    int sum1 , x , y;
    lint w , t;
    rep(k,l,r) {
        scanf("%d",&x);
        rep(j,1,x) scanf("%d",&y) , v[y] = k;
        sum1 = 0;
        for ( lint j = 0; j < 4; j ++ ) if ( v[j] == k ) {
            rep(i,1,sum) {
                w = q[i];
                t = 0;
                rep(p,1,n) {
                    if ( a[p][k] ) w ^= j << t;
                    t += 2;
                }
                q1[++sum1] = w;
            }
        }
        swap( q , q1 );
        swap( sum , sum1 );
    }
    sort( q + 1 , q + 1 + sum );
    q[0] = q[1] - 1;
    sum1 = 0;
    rep(i,1,sum) if ( q[i] == q[sum1] ) {
        s[sum1] ++;
    } else {
        q[++sum1] = q[i];
        s[sum1] = 1;
    }
    sum = sum1;
}

void work()
{
    lint ans = 0 , p = 1;
    deal( 1 , m >> 1 , q1 , q , sum1 , s1 );
    deal( m / 2 + 1 , m , q2 , q , sum2 , s2 );
    rep(i,1,sum1) {
        while ( p < sum2 && q2[p] < q1[i] ) p ++;
        if ( q1[i] == q2[p] ) ans += s1[i] * s2[p];
    }
    cout << ans << endl;
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
