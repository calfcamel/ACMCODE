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
const int MAXN = 40000+ 5;
const int ADD = 20001;
const LL MOD = 1000000000 + 7;

const double PI = acos(-1.0);


///====================================================
///====================================================
struct complex
{
    double r,i;
    complex(double r = 0,double i = 0):r(r),i(i){};
    complex operator + (const complex &b){return complex(r + b.r, i + b.i);}
    complex operator - (const complex &b){return complex(r - b.r, i - b.i);}
    complex operator * (const complex &b){return complex(r * b.r - i * b.i, r * b.i + i * b.r);}
};

void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len / 2; i < len - 1; i++)
    {
        if(i < j) swap(y[i], y[j]);
        k = len >> 1;
        while( j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k)j += k;
    }
}

void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2;h <= len;h <<= 1)
    {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}

//µ÷ÓÃ
//    fft(x1,l,1);
//    fft(x2,l,1);
//    for(i = 0; i < l; i++)
//        x1[i] = x1[i] * x2[i];
//    fft(x1,l,-1);
void conv(complex x[],complex y[],int len)
{
    fft(x,len,1);
    fft(y,len,1);
    for(int i = 0; i < len; i++)
        x[i] = x[i] * y[i];
    fft(x,len,-1);
}

void conv3(complex x[],int len)
{
    fft(x,len,1);
    for(int i = 0; i < len; i++)
        x[i] = x[i] * x[i] * x[i];
    fft(x,len,-1);
}
///====================================================
///====================================================


int ans[MAXN << 2];
int ans2[MAXN << 2];

int a[MAXN];
complex x1[MAXN << 2];
complex x2[MAXN << 2];
int main()
{
    //freopen("h.in","r",stdin);freopen("hh.out","w",stdout);
    int _T;
    _T = 1;
    int N = 1;
    while(_T--)
    {
        int n; scanf("%d",&n);
        LL SUM = 0;
        for(LL i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        N = 1;
        while(N < MAXN * 3) {N <<= 1;}
        //cout << "SUM = " << SUM << " N = " << N << " BIT_CNT = " << BIT_CNT << endl;
        for(int i = 0; i <= N; i++)
            x1[i] = complex(0,0);
        for(LL i = 0; i < n; i++)
            x1[a[i] + ADD].r += 1.0;
        for(int i = 0; i < N; i++)
        {
            x2[i].r = x1[i].r;
            x2[i].i = 0;
        }
        conv3(x1,N);
        for(int i = 0; i < N; i++)
        {
            ans[i] = x1[i].r + .5;
            //if(ans[i])cout << i - 3 * ADD << " : " << ans[i] << endl;
        }

        for(int i = 0; i <= N; i++)
            x1[i] = complex(0,0);
        for(LL i = 0; i < n; i++)
            x1[a[i] + ADD + a[i] + ADD].r += 1.0;
        conv(x1,x2,N);
        for(int i = 0; i < N; i++)
        {
            ans2[i] = x1[i].r + .5;
            //if(ans2[i])cout << i - 3 * ADD << " : " << ans2[i] << endl;
        }
        for(int i = 0; i < n; i++)
        {
            ans[3 * ADD + 3 *a[i]] --;
            ans2[3 * ADD + 3 * a[i]] --;
        }
//        for(int i = 0; i < N; i++)
//        {
//            if(ans[i]) cout << i - 3 * ADD << " : " << ans[i] << " " << ans2[i] << endl;
//        }
        for(int i = 0; i < N; i++)
        if(ans[i]){
            ans[i] -= 3 * ans2[i];
                if(ans[i] / 6 > 0) printf("%d : %d\n",i - 3 * ADD, ans[i] / 6);
        }

    }
}
