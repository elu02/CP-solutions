#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>

using namespace std;

int dist, nClubs, result;
int memo[33][5281];
int clubs[33];

int recurse(int n, int d)
{
    if (memo[n][d] != 0) return memo[n][d];
    if(n == 0 || d > dist)
        return 100;
    else if(d == dist)
        return 0;
    else
    {
        int x = recurse(n-1, d);
        int y = 1 + recurse(n, d+clubs[n]);
        result = min(x, y);
    }
    memo[n][d] = result;
    return result;
}

int main()
{
    int strokes;
    scanf("%d%d", &dist, &nClubs);
    clubs[0] = 0;
    for(int i=1; i<=nClubs; i++)
    {
        int club;
        scanf("%d", &club);
        clubs[i] = club;
    }
    strokes = recurse(nClubs, 0);
    if(strokes == 100)
    {
        printf("Roberta acknowledges defeat.");
        return 0;
    }
    printf("Roberta wins in %d strokes.", strokes);

}