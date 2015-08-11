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
const int MAXN = 100000 + 5;
const LL MOD = 1000000007;
vector<int> V[MAXN];
bool boo[MAXN];
void dfs(int i,int root)
{
    //cout << "dfs " << i << " root = " << root << endl;
    int k = -1;
    for(int j = 0; j < V[i].size(); j++)
    {
        if(V[i][j] == root)
            k = j;
        else
            dfs(V[i][j],i);
    }
    //cout << k << endl;
    if(~k) V[i].erase(V[i].begin() + k);
    if(V[i].size() > 0) boo[i] = 1;
}
LL biao[MAXN];
int main()
{
    int _T;
    int x,y;
    biao[0] = 1;
    for(int i = 1; i < MAXN; i++)
        biao[i] = biao[i - 1] * i % MOD;
    //for(int i = 1; i < 200; i++)
    //    cout << i << " " << biao[i] << endl;
    scanf("%d",&_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        clr(boo,0);
        int n;
        scanf("%d",&n);
        for(int i = 0; i <= n; i++)
            V[i].clear();
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d%d",&x,&y);
            V[y].push_back(x);
            V[x].push_back(y);
        }
        dfs(1,0);
        LL roo;
        LL tot;
        //bool b = 0;
        LL ans = 1;
        for(int i = 1; i <= n; i++)
        {
            tot = 0;
            roo = 0;
            for(int j = 0; j < V[i].size(); j++)
            {
                if(boo[V[i][j]]) roo++;
                tot++;
            }
            if(roo > 2LL) {ans = 0; break;}
            ans = (ans * biao[tot - roo]) % MOD;
            if(roo) ans = ans * 2LL % MOD;
            //cout << i << ' ' << tot << " " << roo << " " << ans << endl;
        }
        if(n > 1) ans = ans * 2LL % MOD;
        printf("Case #%d: %I64d\n",CAS,ans);
    }
}
