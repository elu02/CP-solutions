#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

int numCrystals (int m, int x)
{
    if (m == 0)
        return 0;
    int power = pow(5, m - 1);
    if(x/power == 0 || x/power == 4)
        return 0;
    else if (x/power == 1 || x/power == 3)
        return power + numCrystals(m - 1, x%power);
    else
        return 2 * power + numCrystals(m-1, x%power);
}
int main()
{
    vector<string> outputs;
    int t, m;
    ll x, y;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        scanf("%d%lld%lld", &m, &x, &y);
        if (y < numCrystals(m, x))
            outputs.push_back("crystal");
        else
            outputs.push_back("empty");
    }
    for (int i=0; i<(int)outputs.size(); i++)
    {
        cout << outputs[i] << '\n';
    }
}