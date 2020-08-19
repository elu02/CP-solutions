#include <bits/stdc++.h>
#include<cstdio>
#include<list>
#include<vector>
#include<utility>

using namespace std;

int isFriend(vector< list<int> > friendChain, int friend1, int friend2, int level[])
{
    list<int>::iterator itr;
    bool flag = true;
    int currentLevel = 0;
    level[friend1] = 0;
    while(flag)
    {
        flag = false;
        for(int i=1; i<(int)friendChain.size(); i++)
        {
            if(level[i] == currentLevel)
            {
                //printf("%d %d ", level[i], currentLevel);
                flag = true;
                itr = friendChain[i].begin();
                while(itr != friendChain[i].end())
                {
                    if(*itr == friend2)
                    {
                        //printf("%d %d ", *itr, friend2);
                        return currentLevel;
                    }
                    if(level[*itr] != -1)
                    {
                        itr++;
                        continue;
                    }
                    level[*itr] = currentLevel + 1;
                    itr++;
                }
            }
        }
        currentLevel++;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector< list<int> > friendChain(10000);
    vector<int> out;
    for (int i=0; i<n; i++)
    {
        int giver, reciever;
        scanf("%d%d", &giver, &reciever);
        friendChain[giver].push_back(reciever);
    }
    while(true)
    {
        int level[10000];
        for(int i=0; i<10000; i++)
            level[i] = -1;
        int friend1, friend2, separation;
        scanf("%d%d", &friend1, &friend2);
        if(friend1 == 0 && friend2 == 0)
        {
            break;
        }
        separation = isFriend(friendChain, friend1, friend2, level);
        out.push_back(separation);
    }
    for (int i=0; i<(int)out.size(); i++)
    {
        if (out[i] != -1)
            printf("Yes %d\n", out[i]);
        else
            printf("No\n");
    }
}