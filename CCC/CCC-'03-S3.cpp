#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define sz(x) (int)x.size()
#define pb push_back
#define ll long long
#define vi vector<long long>
#define pi pair<long long, long long>
#define mp make_pair
#define endl '\n'
#define _ << ' '
#define FAST_LOG2(x) (sizeof(unsigned long)*8 - 1 - __builtin_clzl((unsigned long)(x)))
#define clog2(x) (((x) - (1 << FAST_LOG2(x))) ? FAST_LOG2(x) + 1 : FAST_LOG2(x))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> idxset;
//find_by_order(i) : iterator to the value at index i, order_of_key(x) : the index of value x
const ll mod = (ll)1e9+7;
const ll INF = (ll)1e9;
const ll N = (1<<5);
const double PI = 3.1415926535897;

int n, m, f;
vector<int> rooms;
char g[69][69];
int v[69][69];

bool ok(int x, int y){
    if(x==0||y==0||x>n||y>m||v[x][y]||g[x][y]=='I') return 0;
    return 1;
}

int dfs(int x, int y){
    v[x][y] = 1;
    int ret = 1;
    if(ok(x+1, y)) ret += dfs(x+1, y);
    if(ok(x, y+1)) ret += dfs(x, y+1);
    if(ok(x-1, y)) ret += dfs(x-1, y);
    if(ok(x, y-1)) ret += dfs(x, y-1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("B.txt", "r", stdin);
    #endif
    cin >> f >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> g[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(g[i][j]=='.'&&!v[i][j]){
                rooms.pb(dfs(i, j));
            }
        }
    }
    int tot = 0;
    sort(all(rooms), greater<int>());
    for(auto r : rooms){
        if(f>=r){
            f -= r;
            tot++;
        }
        else break;
    }
    cout << tot << " room" << (tot==1?"":"s") << ", " << f << " square metre(s) left over";

}