#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int op[101];
int m, n;
const int INF = 0x3f3f3f3f;
vector< pair<int, string> > people;
int groups[101];
vector<string> ans[20];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int time;
    string name;
    cin >> m >> n;

    for(int i=0; i<n; i++)
    {
        cin >> name >> time;
        people.push_back({time, name});
    }
    for(int i=1; i<101; i++)
        op[i] = INF;
    op[0] = 0;
    for(int i=0; i<n; i++)
    {
        int cs=0;
        for(int j=1; j<=m && i+j<=n; j++)
        {
            cs = max(cs, people[i+j-1].first);
            if(op[i] + cs < op[i+j])
            {
                op[i+j] = op[i] + cs;
                groups[i+j] = j;
            }
        }
    }
    cout << "Total Time: " << op[n] << '\n';
    int k=0;
    for(int i=n; i>0; k++)
    {
        for(int j=0; j<groups[i]; j++)
        {
            ans[k].push_back(people[i-j-1].second);
        }
        i -= groups[i];
    }
    while(k-- > 0)
    {
        for(int i=0; i<ans[k].size(); i++)
        {
            cout << ans[k][i] << " ";
        }
        cout << '\n';
    }
}