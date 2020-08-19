#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define ld long double
#define mkp make_pair
#define sz(x) (int)x.size()
#define pi pair<long long, long long>
#define watch(x) cout << (#x) << " is " << (x) << endl; cout.flush()
#define endl '\n'
#define _ << ' '
#define FAST_LOG2(x) (sizeof(unsigned long)*8 - 1 - __builtin_clzl((unsigned long)(x)))
#define clog2(x) (((x) - (1 << FAST_LOG2(x))) ? FAST_LOG2(x) + 1 : FAST_LOG2(x))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> idxset;
//find_by_order(i) : iterator to the value at index i, order_of_key(x) : the index of value x
const ll mod = (ll)1e9+7;
const ll INF = (ll)1e9+1;

int n, m;
int ar[3003], br[101];
int dp[3003][101][101][2];

int R(int cur, int l, int r, int ok){
    if(cur>n&&l>r) return 0;
    if(dp[cur][l][r][ok]) return dp[cur][l][r][ok];
    int a=0, b=0, c=0, d=0, ret;
    if(ok){
        if(cur<=n) a = ar[cur] + R(cur+1, l, r, 0);
        if(l<=r){
            c = br[r] + R(cur, l, r-1, 0);
        }
    }
    else if(l<=r) d = R(cur, l+1, r, 1);
    if(cur<=n) b = R(cur+1, l, r, 1);
    ret = max( max(a, b), max(c, d) );
    return dp[cur][l][r][ok] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("A.txt", "r", stdin);
    #endif
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> ar[i];
    }
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> br[i];
    }
    sort(br+1, br+m+1);
    R(1, 1, m, 1);
    cout << dp[1][1][m][1];
}