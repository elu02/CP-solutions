#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

#define ii pair<int, int>
#define vi vector<int>
#define vii vector< pair<int, int> >
using namespace std;

struct Edge
{
    int dist, dest, wear;
    Edge(int a, int b, int c)
    {
        dist = a; dest = b; wear = c;
    }
};

vector<Edge> adjList[2002];
int dist[2002][202];
bool inpq[2002];
const int INF = 0x3f3f3f3f;

int main()
{
    int thick, n, m, s, e, a, b, t, w;
    scanf("%d%d%d", &thick, &n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d%d", &a, &b, &t, &w);
        adjList[a].push_back(Edge(t, b, w));    //dist/dest/wear
        adjList[b].push_back(Edge(t, a, w));
    }
    scanf("%d%d", &s, &e);
    memset(dist, INF, sizeof(dist));
    priority_queue< ii, vii, greater<ii> > pq; pq.push(ii(0, s));
    inpq[s] = 1;
    dist[s][0] = 0;
    while(!pq.empty())
    {
        ii currNode = pq.top(); pq.pop(); inpq[currNode.second] = 0;
        for(int i=0; i<(int)adjList[currNode.second].size(); i++)
        {
            Edge v = adjList[currNode.second][i];
            for(int j=0; j+v.wear<thick; j++)
            {
                int d = dist[currNode.second][j] + adjList[currNode.second][i].dist;
                if(dist[v.dest][v.wear+j] > d)
                {
                    dist[v.dest][v.wear+j] = d;
                    if(!inpq[v.dest])
                    {
                        inpq[v.dest] = 1;
                        pq.push(ii(d, v.dest));
                    }
                }
            }
        }
    }
    int path = INF;
    for(int i=0; i<thick; i++)
        if(dist[e][i] < path)
            path = dist[e][i];
    if (path == INF)
        path = -1;
    printf("%d", path);
}