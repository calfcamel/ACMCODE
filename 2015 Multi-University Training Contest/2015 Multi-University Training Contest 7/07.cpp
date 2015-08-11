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
int a[MAXN];
int b[MAXN];
char str[MAXN];
int main()
{
    int _T;
    scanf("%d",&_T);
    int ans;
    int n;
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%s",(str+1));
        str[0] = '0';
        n = strlen(str);
        for(int i = 1; i < n; i++)
            scanf("%d",&a[i]);
        a[0] = 0;
        ans = 0;
        if(str[0] != '0') ans =  a[0];
        int boo;
        for(int i = 1; i < n; i++)
        {
            boo = 0;
            if(str[i] == '?' || str[i - 1] == '?') boo = 1;
            else if(str[i] != str[i - 1]) boo = 1;
            if(boo) ans += a[i];
        }
        for(int i = 0; i < n; i++)
            if(str[i] == '?') b[i] = 2; else b[i] = str[i] - '0';
        b[n] = 0;
        int st = 0;
        while(b[st] == 2 && st < n) st++;
        int AA,BB;
        int tot;
        int jian;
        //cout << st << endl;
        if(st < n)
        {
            for(int i = st; i < n; i++)
            {
                if(i == n - 1) break;
                if(b[i] != 2 && b[i + 1] == 2)
                {
                    AA = b[i];
                    //cout << "sss" << i << endl;
                    tot = 0;
                    jian = a[i + 1];
                }
                if(b[i] == 2)
                {
                    tot ++;
                    jian = min(jian,a[i]);
                }
                if(b[i] == 2 && b[i + 1] != 2)
                {
                    BB = b[i + 1];
                    //cout << AA << " " << BB << " " << tot << endl;
                    if((tot % 2 == 1) && AA != BB)
                    {
                        ans -= min(jian,a[i + 1]);
                    }
                    if((tot % 2 == 0) && AA == BB)
                    {
                        ans -= min(jian,a[i + 1]);
                    }
                }
            }
        }
        printf("Case #%d: %d\n",CAS,ans);
    }
}
