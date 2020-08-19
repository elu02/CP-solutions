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
const ll INF = (ll)1e18+1;

ll n, q;
string s;

string step(int x){
    string ret;
    ll m = (1LL<<x);
    for(int i=0; i<n; i++){
        ll p1 = (n-(m%n)+i)%n;
        ll p2 = (m%n+i)%n;
        ret += to_string((s[p1]-'0')^(s[p2]-'0'));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("B.txt", "r", stdin);
    #endif
    cin >> n >> q >> s;
    for(ll i=0; i<55; i++){
        if((1LL<<i)&q) s = step(i);
    }
    cout << s;
}