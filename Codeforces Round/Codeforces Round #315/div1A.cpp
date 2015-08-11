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
const int MAXN = 2000000 + 5;

int rub[MAXN];
int pi[MAXN];

const int N = MAXN;
LL prime[N];
bool check[N];
void Eular()
{
	clr(check,false);
	int tot = 0;
	for (int i = 2; i < N; i++)
	{
		if (!check[i]) prime[tot++] = i;
		if (!check[i]) pi[i] = 1;
		for (int j = 0; j < tot; j++)
		{
			if (i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int a[15];
int checktot;
int checkrub(int i)
{
    checktot = 0;
    while(i)
    {
        a[checktot++] = i % 10;
        i /= 10;
    }
    i = 0;
    checktot--;
    while(i < checktot)
    {
        if(a[checktot] != a[i]) return 0;
        i++;
        checktot--;
    }
    return 1;
}

void init()
{
    clr(pi,0);
    clr(rub,0);
    Eular();
    for(int i = 1; i < MAXN; i++)
        pi[i] +=pi[i - 1];
    for(int i = 1; i < MAXN; i++)
        rub[i] = checkrub(i);
    for(int i = 1; i < MAXN; i++)
        rub[i] +=rub[i - 1];
    //for(int i = 1; i < MAXN; i++)
        //(pi[i] / rub[i] > 42)cout << i << endl;
    //for(int i = 1; i <= 100; i++)
    //    cout << i << " " << pi[i] << " " << rub[i] << " " << (double)pi[i] / rub[i] << endl;
    //cout << pi[1000000] << endl;
    //cout << rub[1000000] << endl;
    //cout << "END" << endl;
}
int main()
{
    init();
    cout << rub[10] << endl;
    long long p,q;
    cin >> p >> q;
    int ans = MAXN - 100;
    while(1)
    {
        if(q * pi[ans] <= p * rub[ans] || ans == 0)
        {
            //cout << pi[ans] << " " << rub[ans] << endl;
            cout << ans << endl;
            return 0;
        }
        ans--;
    }
    return 0;
}
