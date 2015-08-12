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
#pragma comment(linker, "/STACK:102400000,102400000")
typedef pair<int, int> PII;
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MK make_pair
#define PB push_back
const int MAXN = 1000 + 5;
const LL MOD = 1000000007;

vector<int> V[MAXN];

LL inv[MAXN];
void init_inv(int N)
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
    inv[0] = 0;
}

int vis[MAXN];
int sz[MAXN];
int dfs(int i)
{
    int ret = 1;
    vis[i] = 1;
    for(int j = 0; j < V[i].size(); j++)
    {
        if(!vis[V[i][j]])
            ret += dfs(V[i][j]);
    }
    sz[i] = ret;
    return ret;
}
LL dp[MAXN][MAXN];
int main()
{
    int _T;
    int x,y;
    init_inv(MAXN);
    scanf("%d",&_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        clr(vis,0);
        clr(sz,0);
        clr(dp,0);
        int n; int k;
        scanf("%d %d",&n,&k);
        for(int i = 0; i <= n; i++)
            V[i].clear();
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d%d",&x,&y);
            V[y].push_back(x);
            V[x].push_back(y);
        }
        vis[1] = 1;
        dfs(1);
        //for(int i = 1; i <= n; i++)
        //    cout << i << ": " << sz[i] << endl;
        LL ans;
        sort(sz + 1,sz + n + 1);
        int stj = 0;
        for(int i = 1; i <= n; i++)
            if(sz[i] == 1) stj++;
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i][j] = (inv[sz[i]] * dp[i - 1][j - 1] % MOD + (sz[i] - 1) * inv[sz[i]] % MOD * dp[i - 1][j] % MOD) % MOD;
                //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
            }

        }
        ans = dp[n][k];
        for(LL i = 1; i <= n; i++)
            ans = ans * i % MOD;
        printf("Case #%d: %I64d\n",CAS,ans);
    }
}
