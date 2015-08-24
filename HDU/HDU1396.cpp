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
int main()
{
    f[0] = 0;
    s[0] = 0;
    for(int i = 1; i <= 500; i++)
        f[i] = i;
    for(int i = 1; i <= 500; i++)
        s[i] = s[i - 1] + f[i];
    int n;
    while(scanf("%d",&n) != EOF)
    {
        unsigned long long ans = 0;
        for(int i = 1; i <= n; i++)
            ans += s[i];
        for(int i = 1; i * 2 <= n; i++)
        {
            for(int j = 1; j <= n - 2 * i + 1; j++)
                ans += f[j];
        }
        cout << ans << endl;
    }
}
