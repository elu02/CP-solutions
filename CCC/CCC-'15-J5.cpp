#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
int total=0;
int ways[251][251][126];
int recurse(int n, int k, int p)
{
    if(k==1 || n==k)
        return 1;
    if(ways[n][k][p] == 0)
    {
        for(int i=p; i<=n/k; i++)
        {
            ways[n][k][p] += recurse(n-i, k-1, i);
        }
    }
    return ways[n][k][p];
}
int main()
{
    int k, n;
    scanf("%d%d", &n, &k);
    int ans = recurse(n, k, 1);
    printf("%d", ans);
}