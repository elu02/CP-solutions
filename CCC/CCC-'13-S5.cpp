#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    int t=0;
    scanf("%d", &n);
    while(n!=1)
    {
        int a=1;
        while(n%++a!=0){}
        int b=n/a;
        n-=b;
        t+=n/b;
    }
    printf("%d", t);
}
