#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll mod = (ll)1e9+7;
const ll INF = 1000000002;

int g[3][3];
int nx=0;

void checktwo()
{
    for(int i=0; i<3; i++)
    {
        if(g[i][0]==INF&&g[i][1]!=INF&&g[i][2]!=INF)
        {
            g[i][0]=g[i][1]-(g[i][2]-g[i][1]);
            nx--;
        }
        else if(g[i][1]==INF&&g[i][0]!=INF&&g[i][2]!=INF)
        {
            g[i][1]=g[i][0]+(g[i][2]-g[i][0])/2;
            nx--;
        }
        else if(g[i][2]==INF&&g[i][1]!=INF&&g[i][0]!=INF)
        {
            g[i][2]=g[i][1]+(g[i][1]-g[i][0]);
            nx--;
        }
    }
    for(int i=0; i<3; i++)
    {
        if(g[0][i]==INF&&g[1][i]!=INF&&g[2][i]!=INF)
        {
            g[0][i]=g[1][i]-(g[2][i]-g[1][i]);
            nx--;
        }
        else if(g[1][i]==INF&&g[0][i]!=INF&&g[2][i]!=INF)
        {
            g[1][i]=g[0][i]+(g[2][i]-g[0][i])/2;
            nx--;
        }
        else if(g[2][i]==INF&&g[1][i]!=INF&&g[0][i]!=INF)
        {
            g[2][i]=g[1][i]+(g[1][i]-g[0][i]);
            nx--;
        }
    }
}

void randomlol(bool k)
{
    if(g[1][1]==INF)
    {
        g[1][1]=0;
        nx--;
        return;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(g[i][j]!=INF) continue;
            if(k)
            {
                g[i][j]=0;
                nx--;
                return;
            }
            else
            {
                if(i==0)
                {
                    if(g[2][j]!=INF)
                    {
                        if(g[2][j]&1)
                        {
                            g[i][j]=g[2][j];
                        }
                        else g[i][j]=0;
                        nx--;
                        return;
                    }
                }
                else if(i==1)
                {
                    if(g[1][abs(j-2)]!=INF)
                    {
                        if(g[1][abs(j-2)]&1)
                        {
                            g[i][j]=g[1][abs(j-2)];
                        }
                        else g[i][j]=0;
                        nx--;
                        return;
                    }
                }
                else
                {
                    if(g[0][j]!=INF)
                    {
                        if(g[0][j]&1)
                        {
                            g[i][j]=g[0][j];
                        }
                        else g[i][j]=0;
                        nx--;
                        return;
                    }
                }
                if(j==0)
                {
                    if(g[i][2]!=INF)
                    {
                        if(g[i][2]&1)
                        {
                            g[i][j]=g[i][2];
                        }
                        else g[i][j]=0;
                        nx--;
                        return;
                    }
                }
                else if(j==1)
                {
                    if(g[abs(i-2)][1]!=INF)
                    {
                        if(g[abs(i-2)][1]&1)
                        {
                            g[i][j]=g[abs(i-2)][1];
                        }
                        else g[i][j]=0;
                        nx--;
                        return;
                    }
                }
                else
                {
                    if(g[i][0]!=INF)
                    {
                        if(g[i][0]&1)
                        {
                            g[i][j]=g[i][0];
                        }
                        else g[i][j]=0;
                        nx--;
                        return;
                    }
                }
            }
        }
    }
}

void ok()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("B.txt", "r", stdin);
    #endif
    for(int i=0; i<3; i++)
    {
        string in;
        for(int j=0; j<3; j++)
        {
            cin >> in;
            if(in=="X")
            {
                nx++;
                g[i][j]=INF;
            }
            else g[i][j]=stoi(in);
        }
    }
    while(nx>0)
    {
        int temp=nx;
        checktwo();
        if(temp==nx)
        {
            int temp2=nx;
            randomlol(0);
            if(temp2==nx) randomlol(1);
        }
    }
    ok();
}
