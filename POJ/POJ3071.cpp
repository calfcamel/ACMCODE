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


const int MAXN = (1 << 7) + 5;

int nnn[10];
double p[MAXN][MAXN];
double dp[MAXN][8];
int main()
{
    nnn[0] = 1;
    for(int i = 1; i < 10; i++)
        nnn[i] = nnn[i - 1] * 2;
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n == -1) return 0;
        int l = n;
        n = nnn[n];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%lf",&p[i][j]);
        clr(dp,0);
        for(int i = 1; i <= n; i++)
            dp[i][0] = 1;
        int st;
        int ed;
        for(int k = 1; k <= l; k++)
            for(int i = 1; i <= n; i++)
            {
                st = 1;
                while(st + nnn[k] <= i) st += nnn[k];
                //cout << k << " " << i << ' ' << st << " ";
                //cout << "st + 2^k - 1 = " << st + nnn[k - 1] << " ";
                if(i < st + nnn[k - 1]) st += nnn[k - 1];
                //cout << st << endl;
                dp[i][k] = 0;
                for(int j = 0; j < nnn[k - 1]; j++)
                {
                    dp[i][k] += dp[st + j][k - 1] * p[i][st + j];
                    //cout << i << " vs " << st + j << "  " << p[i][st + j] << " " << dp[st + j][k - 1] << endl;
                }
                dp[i][k] *= dp[i][k - 1];
            }
        int ans;
        double maxp = -1;
//        for(int i = 1; i <= n; i++)
//        {
//            for(int j = 0; j <= l; j++)
//                cout << dp[i][j] << " ";
//            cout << endl;
//        }
        for(int i = 1; i <= n; i++)
        {
            if(maxp < dp[i][l])
            {
                maxp = dp[i][l];
                ans = i;
            }
        }
        cout << ans << endl;

    }
    return 0;
}

