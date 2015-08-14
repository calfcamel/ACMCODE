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
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define NOW a[i][j]
const double PI = acos(-1.0);
const LL MOD = 258280327;


const int MAXN = 100 + 5;
int a[MAXN][MAXN];
vector<PII> Hc[MAXN];
vector<PII> Lc[MAXN];
int H[MAXN][MAXN];
int L[MAXN][MAXN];
int sH[MAXN];
int sL[MAXN];
vector<int> ans;
queue<int> cH;
queue<int> cL;
bool boo[MAXN];
char str[10];
int main()
{
    int _T;
    int n;
    scanf("%d",&_T);
    while(_T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d",&a[i][j]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d",&a[i][j]);
        for(int i = 1; i <= n; i++)
        {
            Hc[i].clear();
            Lc[i].clear();
        }
        clr(H,0);
        clr(L,0);
        clr(sH,0);
        clr(sL,0);
        clr(boo,0);
        ans.clear();
        int xx,yy;
        for(int i = 1; i <= m; i++)
        {
            scanf("%s%d%d",&str,&xx,&yy);
            if(str[0] == 'H')
            {
                Hc[xx].push_back(MP(yy,i));
            }
            else
            {
                Lc[xx].push_back(MP(yy,i));
            }
        }
        //cout << "END READ M" << endl;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                H[i][a[i][j]] ++;
                if(H[i][a[i][j]] == 1) sH[i] ++;
                L[j][a[i][j]] ++;
                if(L[j][a[i][j]] == 1) sL[j] ++;
            }
        while(!cH.empty()) cH.pop();
        while(!cL.empty()) cL.pop();
        int nowi = n;
        int nowj = n;
        int col;
        int mm = m;
        int booooooo = false;
        while(m > 0 && nowi && nowj)
        {
            if(booooooo) break;
            for(int i = 1; i <= n; i++)
                if(sH[i] == 1) cH.push(i);
            for(int j = 1; j <= n; j++)
                if(sL[j] == 1) cL.push(j);
            booooooo = true;
            // H
            while(!cH.empty())
            {
                booooooo = false;
                int x;
                x = cH.front();
                cH.pop();
                sH[x] = -1;

                // find col
                for(int i = 1; i <= n; i++)
                    if(H[x][i]) col = i;

                // get ans
                for(int i = 0; i < Hc[x].size(); i++)
                    if(Hc[x][i].first == col) ans.push_back(Hc[x][i].second);
                for(int i = 0; i < Hc[x].size(); i++)
                    if(Hc[x][i].first != col) ans.push_back(Hc[x][i].second);

                for(int i = 0; i < Hc[x].size(); i++)
                    boo[Hc[x][i].second] = 1;
                //for(int i = 0; i < Hc[x].size(); i++)
                //    cout << Hc[x][i].second << ' '; cout << endl;

                //
                m -= Hc[x].size();
                nowi --;

                // delete

                for(int j = 1; j <= n; j++)
                {
                    L[j][a[x][j]] --;
                    if(L[j][a[x][j]] == 0) sL[j]--;
                }
            }

            // L
            while(!cL.empty())
            {
                booooooo = false;
                int y;
                y = cL.front();
                cL.pop();

                // del
                sL[y] = -1;

                // find col
                for(int i = 1; i <= n; i++)
                    if(L[y][i]) col = i;

                // get ans
                for(int j = 0; j < Lc[y].size(); j++)
                    if(Lc[y][j].first == col) ans.push_back(Lc[y][j].second);
                for(int j = 0; j < Lc[y].size(); j++)
                    if(Lc[y][j].first != col) ans.push_back(Lc[y][j].second);

                for(int j = 0; j < Lc[y].size(); j++)
                    boo[Lc[y][j].second] = 1;
                //for(int j = 0; j < Lc[y].size(); j++)
                //    cout << Lc[y][j].second << ' '; cout << endl;

                //
                m -= Lc[y].size();
                nowj --;

                // delete

                for(int i = 1; i <= n; i++)
                {
                    L[i][a[i][y]] --;
                    if(L[i][a[i][y]] == 0) sH[i]--;
                }
            }
        }
        printf("%d",ans[ans.size() - 1]);
        for(int i = ans.size() - 2; i >= 0; i--)
            printf(" %d",ans[i]);
        puts("");
        for(int i = 1; i <= mm; i++)
            if(boo[i] == 0) ans.push_back(i);
        //cout << "ans" << endl;
        printf("%d",ans[ans.size() - 1]);
        for(int i = ans.size() - 2; i >= 0; i--)
            printf(" %d",ans[i]);
        puts("");
    }
    return 0;
}
