/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月07日 星期五 15时56分29秒
 * File Name: HDU_4285
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
const int mm = 1e9 + 7;
const int HASH = 30007;
int n , m , K , sum , a[14] , b[14] , x , y , now = 0 , nex = 1;
char c[20][20];

struct Hash
{
	int t , h , a[HASH] , n[1001000] , f[1001000];
	lint b[1001000];
	void cl() { t = 0 , clr( a , 0 ); }
	void push(lint s,int sum) {
		h = s % HASH;
		for ( int p = a[h]; p; p = n[p] ) if ( b[p] == s ) {
            f[p] += sum;
            if ( f[p] >= mm ) f[p] -= mm;
            return;
        }
		b[++t] = s; f[t] = sum;
		n[t] = a[h]; a[h] = t;
	}
} f[2];

void deal(lint t)
{
    sum = t & 63;
    t >>= 6;
	rep(i,0,m) a[i] = t & 7 , t >>= 3;
}

lint calc()
{
	lint s = 0 , mx = 0;
	clr( b , 0 );
	rep(i,0,m) if ( a[i] ) a[i] = b[a[i]] ? b[a[i]] : b[a[i]] = ++mx;
	red(i,m,0) s <<= 3 , s |= a[i];
    return s << 6 | sum;
}

void init()
{
    scanf("%d%d%d",&n,&m,&K);
    rep(i,1,n) scanf("%s",c[i]+1);
    f[now].cl(); 
    f[now].push( 0 , 1 );
}

void up(int w,int t,int s)
{
	if ( x && y ) {
        if ( x == y ) {
            int v = 0;
            rep(i,1,t-1) if ( a[i] )
                rep(j,t+1,m) if ( a[i] == a[j] ) v ++;
            if ( !( v & 1 ) && sum ++ < K ) {
                rep(i,0,m) if ( a[i] == y ) a[i] = 0;
                f[nex].push( calc() , s );
            }
        } else {
            rep(i,0,m) if ( a[i] == y ) a[i] = x;
            a[0] = a[t] = 0;
            f[nex].push( calc() , s );
        }
	} else if ( x || y ) {
		x = max( x , y );
		a[0] = x; a[t] = 0;
		if ( c[w][t+1] == '.' ) f[nex].push( calc() , s );
		swap( a[0] , a[t] );
		if ( c[w+1][t] == '.' ) f[nex].push( calc() , s );
	} else if ( c[w][t+1] == '.' && c[w+1][t] == '.' ) {
		a[0] = a[t] = m + 1; 
		f[nex].push( calc() , s );
	}
}

void work()
{
    int ans = 0 , s = 0;
    rep(i,1,n)
        rep(j,1,m) s += c[i][j] == '.';
    if ( s / 4 < K || ( s && !K ) ) {
        puts("0");
        return ;
    }
    rep(i,1,n) rep(j,1,m) {
        f[nex].cl();
        rep(k,1,f[now].t) if ( f[now].f[k] ) {
            deal( f[now].b[k] );
            if ( j == 1 && a[0] ) continue;
            x = a[0]; y = a[j];
            if ( c[i][j] == '*' ) {
                f[nex].push( f[now].b[k] , f[now].f[k] );
            } else {
                up( i , j , f[now].f[k] );
            }
        }
        swap( now , nex );
    }
    rep(i,1,f[now].t) if ( f[now].b[i] == K )
        ( ans += f[now].f[i] ) %= mm;
    printf("%d\n",ans);
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
