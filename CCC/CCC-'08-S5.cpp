#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<long long>
#define pi pair<ll ,ll>
#define watch(x) cout << (#x) << " is " << (x) << endl; cout.flush()
#define endl '\n'
#define _ << ' '
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, d), min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, d), max(b, c))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> idxset;
//find_by_order(i) : iterator to the value at index i, order_of_key(x) : the index of value x
const ll mod = (ll)1e9+7;
const ll INF = (ll)1e18+1;

int q, a, b, c, d;
vector<int> op[5];
int dp[33][33][33][33];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("B.txt", "r", stdin);
    #endif
    op[0].pb(2); op[0].pb(1); op[0].pb(0); op[0].pb(2);
    op[1].pb(1); op[1].pb(1); op[1].pb(1); op[1].pb(1);
    op[2].pb(0); op[2].pb(0); op[2].pb(2); op[2].pb(1);
    op[3].pb(0); op[3].pb(3); op[3].pb(0); op[3].pb(0);
    op[4].pb(1); op[4].pb(0); op[4].pb(0); op[4].pb(1);
    for(int i=0; i<=30; i++)
    {
        for(int j=0; j<=30; j++)
        {
            for(int k=0; k<=30; k++)
            {
                for(int l=0; l<=30; l++)
                {
                    for(int o=0; o<5; o++)
                    {
                        if(i-op[o][0]<0||j-op[o][1]<0||k-op[o][2]<0||l-op[o][3]<0)
                            continue;
                        if(!dp[i-op[o][0]][j-op[o][1]][k-op[o][2]][l-op[o][3]])
                            dp[i][j][k][l]=1;
                    }
                }
            }
        }
    }
    cin >> q;
    while(q--)
    {
        cin >> a >> b >> c >> d;
        cout << (dp[a][b][c][d]?"Patrick":"Roland") << endl;
    }
}