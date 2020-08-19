#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > adj[5001];
vector< pair<int, int> > pencils;
const int INF = 0x3f3f3f3f;
int inpq[5001];
int dist[5001];

int main()
{
    int n, t, k, s, a, b, c;
    scanf("%d%d", &n, &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    scanf("%d", &k);
    for(int i=0; i<k; i++)
    {
        int p, z;
        scanf("%d%d", &z, &p);
        pencils.push_back(make_pair(p, z));
    }
    memset(dist, INF, sizeof(dist));
    scanf("%d", &s);
    dist[s]=0;
    inpq[s]=1;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq; pq.push(make_pair(0, s));
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top(); pq.pop(); inpq[cur.second]=0;
        for(int i=0; i<(int)adj[cur.second].size(); i++)
        {
            if(adj[cur.second][i].first+dist[cur.second] < dist[adj[cur.second][i].second])
            {
                dist[adj[cur.second][i].second] = adj[cur.second][i].first+dist[cur.second];
                if(!inpq[cur.second])
                {
                    inpq[adj[cur.second][i].second] = 1;
                    pq.push(make_pair(adj[cur.second][i].first+dist[cur.second], adj[cur.second][i].second));
                }
            }
        }
    }
    int ans=INF;
    for(int i=0; i<k; i++)
    {
        if(dist[pencils[i].second]+pencils[i].first < ans)
            ans = dist[pencils[i].second]+pencils[i].first;
    }
    printf("%d", ans);
}