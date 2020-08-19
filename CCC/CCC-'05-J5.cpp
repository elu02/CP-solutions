#include <bits/stdc++.h>

#include <iostream>
#include <string>

using namespace std;

string s;

bool isMonkey (string str)
{
    int i = str.length()-1;
    int sc = 0;
    while(i!=-1)
    {
        if(str[i] == 'S')
        {
            int tmp = i-1;
            int tmp2 = 0;
            while(tmp >= 0 && str[tmp] != 'B')
            {
                if(str[tmp] == 'S')
                    tmp2--;
                tmp2++, tmp--;
            }
            if(tmp2%2 == 0)
            {
                return false;
            }
            str.erase(str.begin()+tmp);
            str.erase(str.begin()+i-1);
        }
        i--;
    }

    if(str[(int)str.length()-1] != 'A')
        return false;
    for(int i=0; i<(int)str.length()-1; i++)
    {
        if(str[i] != 'A' && str[i] != 'N')
            return false;
        if(str[i] == 'N')
        {
            if(str[i+1] != 'A')
                return false;
        }
        else if(str[i+1] != 'N')
            return false;
    }
    return true;
}

int main()
{
    while(1)
    {
        bool b = false;
        cin >> s;
        if(s[0] == 'X')
            break;
        b = isMonkey(s);
        if(b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
