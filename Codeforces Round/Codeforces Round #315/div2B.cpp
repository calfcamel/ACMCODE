#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 10000 + 5;

int boo[MAXN];
queue<int> q;
int a[MAXN];
int b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    clr(boo,0);
    clr(b,0);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= 1 && a[i] <= n && boo[a[i]] == 0)
        {
            boo[a[i]] = 1;
            b[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
        if(boo[i] == 0) q.push(i);
    for(int i = 0; i < n; i++)
        if(b[i] == 0)
    {
        a[i] = q.front();
        q.pop();
    }
    printf("%d",a[0]);
    for(int i = 1; i < n; i++)
        printf(" %d",a[i]);
    puts("");
    return 0;
}
