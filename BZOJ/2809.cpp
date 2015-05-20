/*
 * Author:  vawait
 * Created Time:  2015/5/20 14:35:12
 * Problem: BZOJ_2809
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
const int maxn = 101000;
int n , m , q[maxn] , c[maxn] , f[maxn];
int sum = -1 , L[maxn] , R[maxn] , fc[maxn];
pair < int , int > cc[maxn];
vector < int > g[maxn];

struct ZXTree
{
	struct node {
		int l , r , v;
        lint sum;
	} T[maxn*25];
	int sz , root[maxn];
	void ins(int &i,int l,int r,int x) {
	   int m = ( l + r ) >> 1;
	   T[++sz] = T[i]; i = sz;
	   T[i].v ++;
       T[i].sum += fc[x];
	   if ( l == r ) return;
	   if ( x <= m ) ins( T[i].l , l , m , x ); else ins ( T[i].r , m + 1 , r , x );
	}
	int ask(int x,int y,int sum) {
		int l = 1 , r = n , ans = 0;
		x = root[x-1] , y = root[y];
        while ( x != y ) {
            int mid = ( l + r ) >> 1 ; 
            if ( l == r ) {
                ans += min( sum / fc[l] , T[y].v - T[x].v );
                break;
            }
            lint s = T[T[y].l].sum - T[T[x].l].sum;
            if ( s > sum ) {
                x = T[x].l , y = T[y].l , r = mid;
            } else {
                sum -= s , ans += T[T[y].l].v - T[T[x].l].v;
                x = T[x].r , y = T[y].r , l = mid + 1;
            }
        }
		return ans;
	}
	void init() {
		root[0] = sz = 0;
		rep(i,1,n) ins( root[i] = root[i-1] , 1 , n , c[q[i]] );
	}
} T;

void dfs(int t)
{
    q[++sum] = t;
    L[t] = sum;
    red(i,g[t].size()-1,0) dfs( g[t][i] );
    R[t] = sum;
}

void init()
{
    int x;
    scanf("%d%d",&n,&m);
    rep(i,1,n) {
        scanf("%d%d%d",&x,&c[i],&f[i]);
        g[x].pb( i );
        cc[i] = mp( c[i] , i );
    }
    sort( cc + 1 , cc + 1 + n );
    int s = 0;
    cc[0].x = -1;
    rep(i,1,n) {
        if ( cc[i].x != cc[i-1].x ) fc[++s] = cc[i].x;
        c[cc[i].y] = s;
    }
    dfs( 0 );
    T.init();
}

void work()
{
    lint ans = 0;
    rep(i,1,n) ans = max( ans , (lint)f[i] * T.ask( L[i] , R[i] , m ) );
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
}
