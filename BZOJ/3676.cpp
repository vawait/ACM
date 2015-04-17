/*
 * Author:  vawait
 * Created Time:  2015/4/17 18:25:19
 * Problem: BZOJ_3676
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

struct PTree
{
    static const int maxn = 301000;
    static const int maxm = 26;
    int next[maxn][maxm] , len[maxn] , fail[maxn] , num[maxn];
    int sum , last , n;
    char str[maxn];
    int newNode(int l,int f) {
        sum ++;
        rep(i,0,maxm-1) next[sum][i] = 0;
        len[sum] = l;
        fail[sum] = f;
        num[sum] = 0;
        return sum;
    }
    int getFail(int t,int n) {
        while ( str[n-len[t]-1] != str[n] ) t = fail[t];
        return t;
    }
    void init() {
        sum = -1;
        newNode( 0 , 1 );
        newNode( -1 , 0 );
        last = 0;
        //scanf("%s",str+1);
        n = strlen( str + 1 );
        rep(i,1,n) {
            int x = str[i] - 'a' , y = getFail( last , i );
            if ( !next[y][x] ) 
                next[y][x] = newNode( len[y] + 2 , next[getFail(fail[y],i)][x] );
            num[last=next[y][x]] ++;
        }
        red(i,sum,0) num[fail[i]] += num[i];
    }
} PT;

void init()
{
    PT.init();
}

void work()
{
    lint ans = 0;
    rep(i,1,PT.sum)
        ans = max( ans , (lint)PT.len[i] * PT.num[i] );
    cout << ans << endl;
}

int main()
{
    while ( scanf("%s",PT.str+1) != EOF ) {
        init();
        work();
    }
    return 0;
}
