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

#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)

const int MAXN = 100000 + 5;
const LL MOD = 1000000007;

const double PI = acos(-1.0);
int n;
LL sum;
LL s;
int a[MAXN];
LL b[MAXN << 1];
int c[MAXN << 1];
int ret;
int check()
{
    ret = 0;
    sum = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        sum = sum + a[i];
    }
    if(sum % n) return -1;
    s = sum / n;
    int last = -1;
    int duan = -1;
    for(int i = 0; i < n; i++)
    {
        b[i] = a[i] - s;
        b[i + n] = a[i] -s;
        if(b[i] > 2 || b[i] < -2) return -1;
    }
    for(int i = 0; i <= n; i++)
    {
        if(b[i] == 2) duan = i;
        if(b[i] == -2) duan = i;
        if(b[i]) last = i;
        if(b[i] && last != -1 && b[last] == b[i]) duan = i;
        if(duan != -1) break;
    }
    if(duan == -1) duan = 0;
    clr(c,0);
    int next;
    for(int i = duan; i < duan + n; i++)
    {
        next = i + 1;
        if(i == duan + n - 1)
        {
            next = duan;
        }
        if(b[i] > 0)
        {
            b[i] --;
            b[next] ++;
            c[i] --;
            ret ++;
        }
        else if(b[i] < 0)
        {
            b[i] ++;
            b[next] --;;
            c[i] ++;
            ret ++;
        }
        else c[i] = 0;
    }
    //for(int i = duan; i < duan + n; i ++)
     //   cout << b[i] << " "; cout << endl;
    //cout << "duan :" << duan << endl;
    for(int i = duan; i < duan + n; i++)
        if(b[i]) return -1;
    for(int i = 0; i < n; i++)
    {
        b[i] = a[i] - s;
        b[i + n] = a[i] -s;
    }
    return duan;
}
int main()
{
    int _T;
    int duan;
    int next;
    scanf("%d",&_T);
    while(_T--)
    {
        duan = check();
        if((n != 2 && duan != -1) || (n == 2 && ret < 2 && duan != -1))
        {
            puts("YES");
            printf("%d\n",ret);
            for(int j = 2; j >= -2; j--){
            for(int i = duan; i < duan + n; i++)
            {
                if(b[i] != j) continue;
                next = i + 1;
                if(i == duan + n - 1)
                {
                    next = duan;
                }
                if(c[i] == -1) printf("%d %d\n",i % n + 1,next % n+ 1);
                if(c[i] == 1) printf("%d %d\n",next % n + 1,i % n + 1);
            }}
        }
        else puts("NO");
    }
}
