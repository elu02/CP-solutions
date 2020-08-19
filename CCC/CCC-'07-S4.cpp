#include <bits/stdc++.h>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

int visited[10000];
vector< list<int> > adjList(10000);
int n;
int total = 0;

int dfs(int level, int a)
{
    for(list<int>::iterator itr=adjList[a].begin(); itr!=adjList[a].end(); itr++)
    {
        if(*itr == n)
            total += 1;
        else if(!visited[a])
            visited[a] = dfs(0, *itr);
        else
            total += visited[a];
    }
    return total;
}

int main()
{
    scanf("%d", &n);
    int x = -1, y;
    while(x!=0)
    {
        scanf("%d%d", &x, &y);
        adjList[x].push_back(y);
    }
    int ans = dfs(0, 1);
    printf("%d", ans);
}