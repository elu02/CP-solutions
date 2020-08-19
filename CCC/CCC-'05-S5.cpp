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
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> idxset;
//find_by_order(i) : iterator to the value at index i, order_of_key(x) : the index of value x
const ll mod = (ll)1e9+7;
const ll INF = (ll)1e18+1;

int q, x;
idxset se;
double ans=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("B.txt", "r", stdin);
    #endif
    cin >> q;
    double qq=q;
    while(q--)
    {
        cin >> x;
        se.insert(x);
        ans += se.order_of_key(x)+1;
    }
    cout << fixed << setprecision(2) << ans/qq;
}