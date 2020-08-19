#include <bits/stdc++.h>
#define ll long double
#define endl '\n'
using namespace std;
const ll mod = (ll)1e9+7;
const int INF = 0x3f3f3f3f;
ll max(ll a, ll b){return a > b ? a : b;}
ll min(ll a, ll b){return a < b ? a : b;}

int ans;
map<int, int> pho;
vector<int> adj[100001];
vector<int> v(100001);

pair<int, int> bfs(int n)
{
    pair<int, int> ans = {0, 0};
    queue<int> q;
    int d=0;
    q.push(n);
    v[n]=1;
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        if(pho[x])
        {
            ans.second=x;
        }
        for(auto i : adj[x])
        {
            if(!v[i])
            {
                q.push(i);
                v[i]=v[x]+1;
            }
        }
    }
    ans.first=v[ans.second]-1;
    return ans;
}

void bfs2(int n)
{
    queue<int> q;
    q.push(n);
    v[n]=1;
    while(!q.empty())
    {
        ans--;
        int x=q.front(); q.pop();
        for(auto i : adj[x])
        {
            if(pho[i]||v[i]) continue;
            bool ok=0;
            if(adj[i].size()<=2) ok=1;
            else
            {
                for(auto j : adj[i])
                {
                    if(!v[j])
                    {
                        if(!ok) ok=1;
                        else
                        {
                            ok=0;
                            break;
                        }
                    }

                }
            }
            if(ok)
            {
                v[i]=1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("A.txt", "r", stdin);
    #endif
    int n, m, u, x;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> u;
        pho[u]=1;
    }
    for(int i=0; i<n-1; i++)
    {
        cin >> u >> x;
        adj[u].push_back(x);
        adj[x].push_back(u);
    }
    pair<int, int> p1 = bfs(0);
    v.clear(); v.resize(100001);
    pair<int, int> p2 = bfs(p1.second);
    ans=n-1;
    v.clear(); v.resize(100001);
    for(int i=0; i<n; i++)
    {
        if(adj[i].size()<2&&!pho[i])
        {
            bfs2(i);
        }
    }
    cout << ans*2-p2.first;
}
