#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int nPins, balls, weight, result;
int memo[30001][501];

int recurse(int pin, int w, int balls, int pins[])
{
    if(memo[pin][balls] != 0) return memo[pin][balls];
    if(pin == 0 || balls == 0)
    {
        return 0;
    }
    else if(pin-w < 0)
        return 0;
    else
    {
        int val = 0;
        for(int i=0; i<w; i++)
        {
            val += pins[pin-i];
        }
        int x = recurse(pin-1, w, balls, pins);
        int y = val + recurse(pin-w, w, balls-1, pins);
        result = max(x, y);
    }
    memo[pin][balls] = result;
    return result;
}

int main()
{
    int t, val, maxScore;
    vector<int> out;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        scanf("%d%d%d", &nPins, &balls, &weight);
        int pins[nPins+1];
        pins[0] = 0;
        for(int i=1; i<=nPins; i++)
        {
            scanf("%d", &val);
            pins[i] = val;
        }
        for(int i=0; i<30001; i++)
            for(int j=0; j<501; j++)
                memo[i][j] = 0;
        maxScore = recurse(nPins, weight, balls, pins);
        out.push_back(maxScore);
    }
    for(int i=0; i<(int)out.size(); i++)
    {
        printf("%d\n", out[i]);
    }
}
