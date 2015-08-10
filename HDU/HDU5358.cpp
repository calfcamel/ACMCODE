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

const int MAXN = 100000 + 5;
const LL MOD = 1000000000 + 7;

const double PI = acos(-1.0);

#define MP make_pair
#define AA first
#define BB second
#define PB push_back

LL s[MAXN];
LL a[35];

inline LL getans(int l,int r)
{
    if(r - l < 0) return 0;
    LL ret = 0;
    for(int i = l; i <= r; i++)
        for(int j = i; j <= r; j++)
            ret += (LL)i + j;
    return ret;
}
LL pre[MAXN];
LL b[35];
int main()
{
    a[0] = 1;
    b[0] = 1;
    for(int i = 1; i < 35; i++)
        b[i] = i;
    for(int i = 1; i < 35; i++)
        a[i] = a[i - 1] << 1LL;
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        int n;
        int x;
        scanf("%d",&n);
        LL SUM = 0;
        s[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&x);
            SUM += x;
            s[i] = SUM;
            pre[i] = i - 1;
        }
        //cout << "s[i]: ";
        //for(int i = 1; i <= n; i++)
        //    cout << s[i] << " "; cout << endl;
        LL ans = 0;
        LL L = 0;
        LL R = 0;
        for(int k = 0; k < 35; k++)
        {
            if(k && a[k - 1] > SUM) break; /// note
            L = 1;
            R = 0;
            while(L <= n)
            {
                while(R < n && s[R + 1] - s[L - 1] < a[k]) R++; /// find R
                if(pre[L] < R) ans += (L * (R - pre[L]) + (R + pre[L] + 1) * (R - pre[L]) / 2LL) * (b[k]); /// update ans
                //cout << "L = " << L << " R = " << R << " getans = " << (L * (R - pre[L]) + (R + pre[L] + 1) * (R - pre[L]) / 2LL) << " pre[" << L << "] = " << pre[L] << " b[k] = " << b[k] << " ans = " << ans << " count = " << (R - pre[L] + 1) << endl;
                if(pre[L] < R) pre[L] = R; /// update pre
                L ++;
            }
        }
        cout << ans << endl;
    }
}
