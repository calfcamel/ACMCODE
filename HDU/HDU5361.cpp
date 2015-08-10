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

int l[MAXN];
int r[MAXN];
int c[MAXN];
LL ans[MAXN];
int main()
{
    //freopen("1009.in","r",stdin);//freopen("my09.out","w",stdout);
    int _T;
    int n;
    scanf("%d",&_T);
    while(_T--)
    {
        scanf("%d",&n);
        ans[1] = 0;
        priority_queue<pair<LL,PII> > P;
        set<int> S;
        for(int i = 1; i <= n; i++) scanf("%d",&l[i]);
        for(int i = 1; i <= n; i++) scanf("%d",&r[i]);
        for(int i = 1; i <= n; i++) scanf("%d",&c[i]);
        for(int i = 1; i <= n; i++) ans[i] = -1;
        for(int i = 1; i <= n; i++) S.insert(i);
        P.push(MK(0,MK(1,1)));
        set<int>::iterator it,jt;
        int L,R;
        LL p;
        while(!P.empty())
        {
            p = P.top().first * -1LL;
            L = P.top().second.first;
            R = P.top().second.second;
            P.pop();
            it = S.lower_bound(L);
            while(it != S.end())
            {
                if((*it) > R) break;
                ans[(*it)] = p;
                P.push(MK(-(p + c[(*it)]), MK((*it) - r[(*it)], (*it) - l[(*it)])));
                P.push(MK(-(p + c[(*it)]), MK((*it) + l[(*it)], (*it) + r[(*it)])));
                jt = it;
                it++;
                S.erase(jt);
            }
        }

        printf("0");
        for(int i = 2; i <= n; i++) printf(" %I64d",ans[i]);
        puts("");

        //cout << _T << endl;
    }
}
