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
typedef pair<int, int> PII;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define BB second
#define AA first
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
int dp[505];
int tot;
int l[505];
int r[505];
int cnt[505];
int main()
{
    int x,y;
    int n;
    while(scanf("%d",&n) != EOF)
    {
        vector<PII> V;
        V.clear();
        for(int i = 0; i <n; i++)
        {
            scanf("%d%d",&x,&y);
            if(x + y < n) V.PB(MP(x + 1,n - y));
        }
        int ans = 0;
        sort(V.begin(), V.end());
        tot = 0;
        if(V.SZ > 0)
        {
            l[tot] = V[0].AA;
            r[tot] = V[0].BB;
            cnt[tot] = 1;
            tot++;
        }
        for(int i = 1; i < V.SZ; i++)
        {
            if(V[i].AA == V[i - 1].AA && V[i].BB == V[i - 1].BB)
            {
                cnt[tot - 1] ++;
            }
            else
            {
                l[tot] = V[i].AA;
                r[tot] = V[i].BB;
                cnt[tot] = 1;
                tot++;
            }
        }
        for(int i = 0; i < tot; i++)
        {
            cnt[i] = min(cnt[i],r[i] - l[i] + 1);
        }
//        for(int i = 0; i < tot; i++)
//        {
//            cout << i << " " << l[i] << " " << r[i] << " " << cnt[i] << endl;
//        }
        clr(dp,0);
        for(int i = 0; i < tot; i++)
        {
            dp[r[i]] = max(dp[r[i]], dp[l[i] - 1] + cnt[i]);
            for(int j = r[i] + 1; j <= n; j++)
                dp[j] = max(dp[j], dp[r[i]]);
        }
        printf("%d\n",dp[n]);
    }
}
