//calfcamel
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

const int MAXN = 3 * 100000 + 5;
const int MAXDP = 5000 + 5;
LL dp[MAXDP][MAXDP];
LL a[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++)
        scanf("%I64d",&a[i]);
    sort(a + 1,a + n + 1);
    a[0] = 0;
    a[0] = 0;
    LL ans = 0;
    int A = n % k;
    int LA = n / k + 1;
    int B = k - n % k;
    int LB = n / k;

    clr(dp,0);
    for(int i = 0; i <= A; i++)
        for(int j = 0; j <= B; j++)
    {
        if(i == 0 && j == 0) continue;
        else if(i == 0) dp[i][j] = dp[i][j - 1] + a[i * LA + j * LB] - a[i * LA + (j - 1) * LB + 1];
        else if(j == 0) dp[i][j] = dp[i - 1][j] + a[i * LA + j * LB] - a[(i - 1) * LA + j * LB + 1];
        else
            dp[i][j] = min(dp[i - 1][j] + a[i * LA + j * LB]- a[(i - 1) * LA + j * LB + 1],
                           dp[i][j - 1] + a[i * LA + j * LB]- a[i * LA + (j - 1) * LB + 1]);


    }
    cout << dp[A][B] << endl;
    return 0;
}
