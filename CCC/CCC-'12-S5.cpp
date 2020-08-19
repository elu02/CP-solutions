#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
#define ll long long
int main()
{
    ll r, c, cages;
    scanf("%lld%lld%lld", &r, &c, &cages);
    ll arr[r+1][c+1] = { 0 };
    arr[1][1] = 1;

    for (int i=0; i<=r; i++)
        arr[i][0] = 0;
    for (int i=0; i<=c; i++)
        arr[0][i] = 0;
    arr[0][1] = 1;
    for (int i=0; i<cages; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        arr[x][y] = -1;
    }
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if (arr[i][j] != -1)
            {
                if (arr[i-1][j] < 0 && arr[i][j-1] < 0)
                    arr[i][j] = -2;
                else if(arr[i-1][j] < 0)
                    arr[i][j] = arr[i][j-1];
                else if(arr[i][j-1] < 0)
                    arr[i][j] = arr[i-1][j];
                else
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
    }
    /*for (int i=0; i<=r; i++)
    {
        for (int j=0; j<=c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    */
    if (arr[r][c] > 0)
        printf("%lld", arr[r][c]);
    else
        printf("0");
    return 0;
}