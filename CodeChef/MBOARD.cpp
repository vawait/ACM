/*
 * Author:  vawait
 * Created Time:  2014/10/28 16:37:17
 * File Name: CodeChefMBOARD.cpp
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
int x , y , n , m , t[2][maxn] , v[2][maxn];
char s[100];

struct bit
{
    int t[maxn] , n;
    void cl(int N) { 
        n = N;
        rep(i,0,n) t[i] = 0;
    }
    void add(int x,int y) {
        for ( ; x <= n; x += x & (-x) ) t[x] += y;
    }
    int sum(int x) {
        int s = 0;
        for ( ; x; x -= x & (-x) ) s += t[x];
        return s;
    }
    int ask(int l,int r) {
        return sum( r ) - sum( l - 1 );
    }
} T[2][2];


void init()
{
    rep(i,0,1)
        rep(j,0,1) T[i][j].cl( m );
    rep(i,0,n) 
        rep(j,0,1) t[j][i] = v[j][i] = 0;
}

void ask(int k)
{
    if ( v[k][x] == 1 ) {
        printf("%d\n",T[1^k][0].ask( t[k][x] + 1 , m ) );
    } else {
        printf("%d\n", n - T[1^k][1].ask( t[k][x] + 1 , m ) );
    }
}

void cha(int k,int tt)
{
    scanf("%d",&y);
    if ( t[k][x] ) T[k][v[k][x]].add( t[k][x] , -1 );
    t[k][x] = tt;
    v[k][x] = y;
    T[k][v[k][x]].add( t[k][x] , 1 );
}

void work()
{
    rep(i,1,m) {
        scanf("%s%d",s,&x);
        if ( s[3] == 'Q' ) ask( s[0] == 'C' ); else cha( s[0] == 'C' , i );
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
