#include <bits/stdc++.h>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    int g, p, input;
    scanf("%d%d", &g, &p);
    set<int> gates;
    for(int i=1; i<=g; i++)
    {
        gates.insert(i);
    }
    for(int i=0; i<p; i++)
    {
        scanf("%d", &input);
        if(gates.upper_bound(input) == gates.begin())
        {
            printf("%d\n", i);
            return 0;
        }
        if(gates.lower_bound(input) == gates.upper_bound(input))
        {
            set<int>::iterator itr = gates.lower_bound(input);
            itr--;
            gates.erase(itr);
        }
        else
            gates.erase(gates.lower_bound(input));
    //for(set<int>::iterator i=gates.begin(); i!=gates.end(); i++)
            //printf("%d ", *i);
    }
    printf("%d", p);
}
