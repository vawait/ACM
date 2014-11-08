/*
 * Author:  Twist Of Fate
 * Created Time:  2014年11月08日 星期六 12时46分57秒
 * File Name: HDU_4006
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
int n , k , sum;
char c[10];

void init()
{
    sum = 0;
}

void work()
{
    int x;
    priority_queue < int > q;
    while ( n -- ) {
        scanf("%s",c);
        if ( c[0] == 'I' ) {
            scanf("%d",&x);
            q.push( -x );
            sum ++;
            while ( sum > k ) q.pop() , sum --;
        } else {
            printf("%d\n",-q.top());
        }
    }
}

int main()
{
    while ( cin >> n >> k ) {
        init();
        work();
    }
    return 0;
}
