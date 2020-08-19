#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    string s;
    int level;
};
int main() //min = (length - one) * 2
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l;
    cin >> l;
    for(int o=0; o<l; o++)
    {
        map<string, vector<string> > names;
        map<string, bool> visited;
        int n;
        bool f=true;
        string prev, next, home;
        cin >> n;
        cin >> prev;
        for(int i=0; i<n-2; i++)
        {
            cin >> next;
            names[prev].push_back(next);
            names[next].push_back(prev);
            visited[prev] = 0;
            prev = next;
        }
        cin >> home;
        names[prev].push_back(home);
        names[home].push_back(prev);
        queue<Node> bfsq;
        bfsq.push({home, 0});
        visited[home]=1;
        int counter;
        while(!bfsq.empty())
        {
            Node cur = bfsq.front();
            bfsq.pop();
            for(int i=0; i<(int)names[cur.s].size(); i++)
            {
                if(!visited[names[cur.s][i]])
                {
                    bfsq.push({names[cur.s][i], cur.level+1});
                    visited[names[cur.s][i]] = 1;
                }
            }
            counter = cur.level;
        }
        cout << (n-((counter)*2)) * 10 << '\n';
    }
}