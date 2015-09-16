/*
 * Author:  vawait
 * Created Time:  2015/9/16 13:56:32
 * Problem: SPOJ NSUBSTR Substrings
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

struct SAM
{
    static const int maxn = 251000;
    struct node {
        int fa , len , sum , d , ch[26];
    } a[maxn<<1];
    int last , len , cnt , n , f[maxn] , d[maxn<<1] , q[maxn<<1];
    char s[maxn<<1];
    int newNode() {
        return ++cnt;
    }
    void add(int x) {
        int p = last;
        last = newNode();
        a[last].len = ++len;
        a[last].sum = 1;
        for ( ; p && !a[p].ch[x]; p = a[p].fa ) a[p].ch[x] = last;
        if ( !p ) a[last].fa = 1; else {
            int next = a[p].ch[x];
            if ( a[next].len == a[p].len + 1 ) a[last].fa = next; else {
                int r = ++cnt;
                rep(i,0,25) a[r].ch[i] = a[next].ch[i];
                a[r].len = a[p].len + 1;
                a[r].fa = a[next].fa;
                a[last].fa = a[next].fa = r;
                for ( ; p && a[p].ch[x] == next ; p = a[p].fa ) a[p].ch[x] = r;
            }
        }
    }
    void init() {
        int x , sum = 0;
        cnt = 0;
        last = newNode();
        len = 0;
        
        scanf("%s",s+1);
        n = strlen( s + 1 );
        rep(i,1,n) add( s[i] - 'a' );
        rep(i,1,cnt) d[a[i].fa] ++;
        rep(i,2,cnt) if ( !d[i] ) q[++sum] = i;
        rep(i,1,sum) if ( !( --d[a[q[i]].fa] ) ) q[++sum] = a[q[i]].fa;
        rep(i,1,cnt-1) {
            x = q[i];
            f[a[x].len] = max( f[a[x].len] , a[x].sum );
            a[a[x].fa].sum += a[x].sum;
        }
        red(i,n-1,1) f[i] = max( f[i] , f[i+1] );
        rep(i,1,n) printf("%d\n",f[i]);
    }
} sam;

void init()
{
    sam.init();
}

void work()
{
}

int main()
{
    init();
    work();
    return 0;
}
