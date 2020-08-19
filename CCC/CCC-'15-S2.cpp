#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define all(a) a.begin(), a.end()
#define sz(a) a.size()
#define pb push_back
using namespace std;

const ll mod = 1e9+7;

char a[1000001];
int ans=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("A.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        char c; int x;
        cin >> c >> x;
        if(c>=a[x-1]){
            a[x-1]='z';
            ans++;
        }
    }
    cout << ans << endl;
}