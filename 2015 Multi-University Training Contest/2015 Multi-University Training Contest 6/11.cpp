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

#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)

const int MAXN = 10000 + 5;
const LL MOD = 1000000007;

const double PI = acos(-1.0);
LL pw(LL x,LL y)
{
    LL ret = 1;
    if(y == 0) return 1;
    while(y)
    {
        if(y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}
int a[MAXN];
LL s[MAXN];
LL SUM[MAXN];
LL ans;
LL now;
int main()
{
    int _T;
    int n;
    int ans;
    scanf("%d",&_T);
    while(_T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",a[i]);
        s[0] = a[0];
        for(int i = 1; i < n; i++)
            s[i] = s[i - 1] + a[i];
        SUM[0] = s[0];
        for(int i = 1; i < n; i++)
            SUM[i] = SUM[i - 1] + s[i];
        now = 0;
        for(int i = 0; i < n; i++)
        {

        }
    }
    return 0;
}
