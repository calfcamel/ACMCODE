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
int n,t;
LL now;
LL sum;
LL a[100];
LL b[100];
LL tot;
LL ans;
int main()
{
    int _T = 1;
    b[0] = 1;
    for(int i = 1; i < 60; i ++)
        b[i] = (b[i - 1] * 10LL) % 11LL;
    //for(int i = 0; i < 10; i ++)
    //    cout << i << " " << b[i] << endl;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        if(n == -1 && t == -1) return 0;
        now = n;
        sum = 0;
        ans = n % 11;
        while(now)
        {
            a[tot] = now % 10;
            sum += a[tot];
            tot++;
            now = now / 10;
        }
        //cout << sum << endl;
        while(t--)
        {
            tot = 0;
            now = sum;
            while(now)
            {
                a[tot] = now % 10;
                sum += a[tot];
                tot++;
                now = now /10;
            }
            //cout << sum << endl;
            ans = ans * b[tot] % 11;
            for(int i = 0; i < tot; i++)
            {
                ans = (ans + a[i] * b[i]) % 11;
            }
        }
        printf("Case #%d: ",_T);
        _T++;
        //cout << ans << endl;
        if(ans) puts("No");
        else puts("Yes");
    }
}
