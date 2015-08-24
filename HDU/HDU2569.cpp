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
unsigned long long f[505];
unsigned long long s[505];

int dp[50][3][3];
int ans[50];
int main()
{
    clr(ans,0);
    ans[1] = 3;
    clr(dp,0);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            dp[2][i][j] = 1;
    for(int i = 3; i <= 40; i ++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
            {
                if(j == k)
                {
                    for(int l = 0; l < 3; l++)
                        dp[i][j][k] += dp[i - 1][l][j];
                }
                else
                {
                    dp[i][j][k] += dp[i - 1][j][j];
                    dp[i][j][k] += dp[i - 1][k][j];
                }
            }
    for(int i = 2; i <= 40; i ++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                ans[i] += dp[i][j][k];
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
