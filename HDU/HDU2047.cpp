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


unsigned long long dp[50][3];
unsigned long long ans[50];
int main()
{
    clr(ans,0);
    clr(dp,0);
    for(int i = 0; i < 3; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= 40; i ++)
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                dp[i][j] += dp[i - 1][1];
                dp[i][j] += dp[i - 1][2];
            }
            else
            {
                dp[i][j] += dp[i - 1][0];
                dp[i][j] += dp[i - 1][1];
                dp[i][j] += dp[i - 1][2];
            }
        }
    for(int i = 1; i <= 40; i ++)
        for(int j = 0; j < 3; j++)
            ans[i] += dp[i][j];
    int n;
    while(scanf("%d",&n)!= EOF)
    {
        printf("%I64u\n",ans[n]);
    }
    return 0;
}
