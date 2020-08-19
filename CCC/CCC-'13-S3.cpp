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

int f, g;
vector< vector<int> > v(5, vector<int>(5) );
vector<int> s(10);

int R(vector<int> s){
    int ret = 0, ok = 0;
    for(int i=1; i<=4; i++){
        for(int j=i+1; j<=4; j++){
            if(!v[i][j]){
                v[i][j] = v[j][i] = 1;
                vector< vector<int> > c = v;
                s[i] += 3;
                ret += R(s);
                v = c;
                s[i] -= 3;
                s[j] += 3;
                ret += R(s);
                v = c;
                s[j] -= 3;
                s[i] += 1;
                s[j] += 1;
                ret += R(s);
                ok = 1;
                break;
            }
        }
        if(ok) break;
    }
    if(!ok){
        for(int i=1; i<=4; i++){
            if(i==f) continue;
            if(s[i]>=s[f]) return 0;
        }
        return 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C.txt", "r", stdin);
    #endif
    cin >> f >> g;
    for(int i=0; i<g; i++){
        int aa, bb, s1, s2;
        cin >> aa >> bb >> s1 >> s2;
        v[aa][bb] = v[bb][aa] = 1;
        if(s1>s2){
            s[aa]+=3;
        }
        else if(s2>s1){
            s[bb]+=3;
        }
        else{
            s[aa]++;
            s[bb]++;
        }
    }
    int ans = R(s);
    cout << ans;
}