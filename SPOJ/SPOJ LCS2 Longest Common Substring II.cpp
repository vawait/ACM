/*
 * Author:  vawait
 * Created Time:  2015/9/15 13:31:20
 * Problem: SPOJ LCS2 Longest Common Substring II
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
        int fa , len , ch[26] , max , min;
    } a[maxn<<1];
    int last , len , cnt;
    char s[maxn<<1];
    int newNode() {
        return ++ cnt;
    }
    void add(int x) {
        int p = last;
        last = newNode();
        a[last].len = ++len;
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
        cnt = 0;
        last = newNode();
        len = 0;
        scanf("%s",s+1);
        int n = strlen( s + 1 ) , ans = 0 , l , x , p;
        rep(i,1,n) add( s[i] - 'a' );
        rep(i,1,cnt) a[i].min = a[i].len;
        
        while ( scanf("%s",s+1) != EOF ) {
            n = strlen( s + 1 );
            p = 1 , l = 0;
            rep(i,1,cnt) a[i].max = 0;
            rep(i,1,n) {
                x = s[i] - 'a';
                if ( a[p].ch[x] ) {
                    l ++; 
                    p = a[p].ch[x];
                } else {
                    while ( p && !a[p].ch[x] ) p = a[p].fa;
                    if ( p ) {
                        l = a[p].len + 1;
                        p = a[p].ch[x];
                    } else {
                        l = 0;
                        p = 1;
                    }
                }
                a[p].max = max( a[p].max , l );
            }
            rep(i,1,cnt) {
                a[i].min = min( a[i].min , a[i].max );
                a[a[i].fa].max = max( a[a[i].fa].max , a[i].max );
            }
        }
        rep(i,1,cnt) ans = max( ans , a[i].min );
        cout << ans << endl;
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
