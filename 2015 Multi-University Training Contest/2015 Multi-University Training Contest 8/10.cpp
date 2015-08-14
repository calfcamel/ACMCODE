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
const LL MOD = 258280327;


const int MAXN = 10000 + 5;
LL a[10];
LL b[10];
int add[10][10];
inline int calc(int i,int j)
{
    int ret = i + j;
    if(ret >= 10) ret = ret % 10 + 1;
    return ret;
}
int main()
{
    int _T;
    int x;
    int n,A,B;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            add[i][j] = calc(i , j);
    /*for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            cout << i << ' ' << j << " " << add[i][j] << endl;*/
    scanf("%d",&_T);
    while(_T--)
    {
        LL ans = 0;
        int sum = 0;
        scanf("%d%d%d",&n,&A,&B);
        for(int i = 0; i < 10; i++) a[i] = 0;
        a[0] = 1;
        for(int in = 0; in < n; in++)
        {
            scanf("%d",&x);
            sum = add[sum][x];
            for(int i = 0; i < 10; i++)
                b[i] = 0;
            for(int i = 0; i < 10; i++)
            {
                b[add[i][x]] = (b[add[i][x]] + a[i]) % MOD;
            }
            /*cout << "B: ";
            for(int i = 0; i < 10; i++)
                cout << b[i] << " ";
            cout << endl;*/
            for(int i = 0; i < 10; i++)
                a[i] = (a[i] + b[i]) % MOD;
            /*cout << "A: ";
            for(int i = 0; i < 10; i++)
                cout << a[i] << " ";
            cout << endl;*/
        }
        //cout << "SUM: " << sum << endl;
        if(sum == B) ans = 1;
        if(sum = add[A][B]) ans += a[A];
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}
