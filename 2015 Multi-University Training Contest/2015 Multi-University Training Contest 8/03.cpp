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
const int MAXN = 1000000 + 5;
const LL MOD = 258280327;
LL pp[MAXN];
LL t[MAXN];
LL prime[MAXN / 8];
LL tot_prime;

LL mi[100];

LL f[MAXN];
LL F[MAXN];
LL S[MAXN];
void init_p()
{
    tot_prime = 0;
    pp[0] = 0;
    pp[1] = 0;
    for(int i = 2; i < MAXN; i++)
    {
        if(pp[i]) continue;
        prime[tot_prime++] = i;
        for(int j = i; j < MAXN; j += i)
        {
            pp[j] ++;
        }
    }
    mi[0] = 1;
    for(int i = 1; i < 100; i++)
        mi[i] = mi[i - 1] * 2LL % MOD;
    for(int i = 1; i < MAXN; i++)
        pp[i] = mi[pp[i]];
    for(int i = 1; i < MAXN; i++)
        t[i] = pp[i - 1];
    memset(f,0,sizeof f);
    for(int i = 2; i < MAXN; i++)
    {
        for(int j = i; j < MAXN; j += i)
            f[j] = (f[j] + t[i]) % MOD;
    }
    memset(F,0,sizeof F);
    F[0] = 0;
    for(int i = 1; i < MAXN; i++)
        F[i] = (F[i - 1] - f[i - 1] + 2LL * i - 1 + MOD + MOD) % MOD;
    S[0] = 0;
    for(int i = 1; i < MAXN; i++)
        S[i] = (S[i - 1] + F[i]) % MOD;
}
int main()
{
    init_p();
    int _T;
    int x;
    ///DEBUG
    //for(int i = 0; i <= 100; i++)
    //    cout << i << " " << pp[i] << " " << t[i] << " " << f[i] << " " << F[i] << " " << S[i] << endl;
    ///DEBUG
    scanf("%d",&_T);
    while(_T--)
    {
        scanf("%d",&x);
        printf("%I64d\n",S[x]);
    }
}
