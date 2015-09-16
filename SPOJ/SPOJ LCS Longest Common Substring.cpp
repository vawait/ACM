/*
 * Author:  vawait
 * Created Time:  2015/9/11 14:17:42
 * Problem: SPOJ LCS Longest Common Substring
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
        int fail , len , ch[26];
    } a[maxn<<1];
    int last , len , cnt;
    char s[maxn<<1];
    int newNode() {
        a[++cnt].len = 0;
        a[cnt].fail = 0;
        clr( a[cnt].ch , 0 );
        return cnt;
    }
    void add(int x) {
        int p = last;
        last = newNode();
        a[last].len = ++len;
        for ( ; p && !a[p].ch[x]; p = a[p].fail ) a[p].ch[x] = last;
        if ( !p ) a[last].fail = 1; else {
            int next = a[p].ch[x];
            if ( a[next].len == a[p].len + 1 ) a[last].fail = next; else {
                int r = ++cnt;
                rep(i,0,25) a[r].ch[i] = a[next].ch[i];
                a[r].len = a[p].len + 1;
                a[r].fail = a[next].fail;
                a[last].fail = a[next].fail = r;
                for ( ; p && a[p].ch[x] == next ; p = a[p].fail ) a[p].ch[x] = r;
            }
        }
    }
    void init() {
        cnt = 0;
        last = newNode();
        len = 0;
        
        scanf("%s",s+1);
        int n = strlen( s + 1 ) , ans = 1e9 , p = 1 , x;
        rep(i,1,n) add( s[i] - 'a' );
        
        while ( scanf("%s",s+1) != EOF ) {
            n = strlen( s + 1 );
            int mx = 0 , r = 0;
            rep(i,1,n) {
                x = s[i] - 'a';
                if ( a[p].ch[x] ) {
                    r ++;
                    p = a[p].ch[x];
                } else {
                    while ( p && !a[p].ch[x] ) p = a[p].fail;
                    if ( !p ) p = 1 , r = 0; else {
                        r = a[p].len + 1;
                        p = a[p].ch[x];
                    }
                }
                mx = max( mx , r );
            }
            ans = min( mx , ans );
        }
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
