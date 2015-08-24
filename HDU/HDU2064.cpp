#include<stdio.h>
#include<iostream>
using namespace std;
unsigned long long f[100];
int main()
{
    f[1] = 2;
    for(int i = 2; i <= 35; i++)
    {
        f[i] = f[i - 1] * 3 + 2;
        //cout << i << " " << f[i] << endl;
    }
    int n;
    while(scanf("%d",&n) != EOF)
    {
        cout << f[n] << endl;
    }
}
