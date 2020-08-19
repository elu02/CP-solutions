#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int LCP(string s1, string s2)
{
    int l = min(s1.length(), s2.length());
    for(int i=0; i<l; i++)
        if(s1[i]!=s2[i])
            return i;
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        string temp;
        string suffix[5010];
        cin >> str;
        int len = str.length();
        for(int j=len-1; j>=0; j--)
        {
            suffix[j] = str.substr(j);
        }
        sort(suffix, suffix+len);
        int ans=suffix[0].length();
        for(int i=1; i<len; i++)
            ans += suffix[i].length()-LCP(suffix[i], suffix[i-1]);
        cout << ans+1 << '\n';
    }
}
