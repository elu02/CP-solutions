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

map<char, int> ans[11];
map<string, vector<string> > mp;
map<string, int> v;

void dfs(string cur, string p){
    v[cur] = 1;
    for(auto nxt : mp[cur]){
        if(p.find(nxt)!=string::npos){
            ans[cur[1]-48][cur[0]] = -1;
            return;
        }
        if(v[nxt]){
            if(ans[nxt[1]-48][nxt[0]]==-1){
                ans[cur[1]-48][cur[0]] = -1;
                return;
            }
            else ans[cur[1]-48][cur[0]] += ans[nxt[1]-48][nxt[0]];
            continue;
        }
        dfs(nxt, p + nxt);
        if(ans[nxt[1]-48][nxt[0]]==-1) ans[cur[1]-48][cur[0]] = -1;
        else ans[cur[1]-48][cur[0]] += ans[nxt[1]-48][nxt[0]];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C.txt", "r", stdin);
    #endif
    string t;
    for(int i='A'; i<='J'; i++){
        for(int j=1; j<=9; j++){
            cin >> t;
            string r = ""; r += i; r += to_string(j);
            if(t[0]<65){
                v[r] = 1;
                ans[j][i] = stoi(t);
            }
            else{
                for(int k=0; k<t.size(); k+=3){
                    string s = t.substr(k, 2);
                    mp[r].pb(s);
                }
            }
        }
    }
    for(int i='A'; i<='J'; i++){
        for(int j=1; j<=9; j++){
            string r = ""; r += i; r += to_string(j);
            if(!v[r]) dfs(r, r);
            if(ans[j][i]==-1) cout << '*' _;
            else cout << ans[j][i] _;
        }
        cout << endl;
    }
}