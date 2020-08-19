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
//#define mp make_pair
//#define endl '\n'
#define _ << ' '
#define double long double
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

int cnt[2001], h[4001], in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C.txt", "r", stdin);
    #endif
    int n, mx=0, cmx=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in;
        cnt[in]++;
    }
    for(int i=1; i<=2000; i++){
        for(int j=i; j<=2000; j++){
            if(i==j) h[i+j] += cnt[i]/2;
            else h[i+j] += min(cnt[i], cnt[j]);
        }
    }
    for(int i=0; i<=4000; i++){
        if(h[i]>mx){
            cmx = 1;
            mx = h[i];
        }
        else if(h[i]==mx){
            cmx++;
        }
    }
    cout << mx _ << cmx;
}