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
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MK make_pair
#define PB push_back
const int MAXN = 200000 + 5;
const LL MOD = 1000000007;
int str[MAXN];
int n;
int p[MAXN];
int dp[MAXN];
void pk()
{
    int i;
    int mx = 0;
    int id;
    for(i=1; i<n; i++)
    {
        if( mx > i )
            p[i] = min( p[2*id-i], mx-i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

set<int> S;
vector<int> V[MAXN];
int main()
{
    //freopen("erge.in","r",stdin);
    int _T;
    int ans;
    scanf("%d",&_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d",&n);
        clr(str,-1);
        clr(dp,0);
        clr(p,0);
        for(int i = 0; i < n; i++)
            scanf("%d",&str[i * 2 + 1]);
        n = n * 2 + 1;
        pk();
        //for(int i = 0; i < n; i++)
        //    printf("%2d ",i);puts("");
        //for(int i = 0; i < n; i++)
        //    printf("%2d " ,p[i]);puts("");
        int update = 0;
        for(int i = 0; i < n; i++)
        {
            update = max(update,i);
            while(update <= i + p[i]) dp[update++] = i;
        }
        //for(int i = 0; i < n; i++)
        //    printf("%2d " ,dp[i]);puts("");
        for(int i = 0; i < n; i+= 2)
            V[i].clear();
        for(int i = 0; i < n; i++)
            p[i] -= p[i] & 1;
        S.clear();
        ans = 0;
        set<int>::iterator j;
        for(int i = 0; i < n; i+= 2)
        {
            S.insert(i);
            if(i + p[i] < n) V[i + p[i]].push_back(i);
            //cout << "SET " << i << ":" << endl;
            //cout << "\t";
            //for(set<int>::iterator i = S.begin(); i != S.end(); i++)
            //    cout << (*i) << " " ; cout << endl;
            j = S.lower_bound(i - p[i]);
            if(j != S.end())ans = max(ans,i - (*j));
            for(int k = 0; k < V[i].size(); k++)
            {
                S.erase(V[i][k]);
            //    cout << "ERASE " << V[i][k] << endl;
            }
        }
        printf("Case #%d: %d\n",CAS,ans / 2 * 3);
    }
}
