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
#define pi pair<int, int>
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

int n, ans=0;
int dp[411][411]; // dp[i][j] = max riceball int range [i, j]

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("B.txt", "r", stdin);
    #endif
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &dp[i][i]);
        ans = max(ans, dp[i][i]);
    }
    for(int x=1; x<n; x++)
    {
        for(int i=0; i+x<n; i++)
        {
            for(int j=i; j<i+x; j++)
            {
                if(dp[i][j]==dp[j+1][i+x])
                {
                    dp[i][i+x]=max(dp[i][i+x], dp[i][j]+dp[j+1][i+x]);
                    ans=max(ans, dp[i][i+x]);
                }
                for(int k=j+2; k<=i+x; k++)
                {
                    if(!dp[j+1][k-1]||!dp[i][j]) continue;
                    if(dp[i][j]==dp[k][i+x])
                    {
                        int a = dp[j+1][k-1];
                        dp[i][i+x]=max(dp[i][i+x], dp[i][j]+dp[k][i+x]+a);
                        ans=max(ans, dp[i][i+x]);
                    }
                }
            }
        }
    }
    printf("%d", ans);
}