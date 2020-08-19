#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct Coord
{
    int x;
    int y;
};
struct Node
{
    Coord coord;
    int level;
};
int main()
{
    vector<int> out;
    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int rows, cols;
        cin >> rows >> cols;
        char matrix[rows+2][cols+2] = { 0 };
        int visited[rows+2][cols+2] = { 0 };
        Coord endxy = {rows, cols};
        queue<Node> bfsq;
        Coord c = {1, 1};
        Node s = {c, 1};
        bfsq.push(s);
        int lr[4] = {0, 0, 1, -1};  //left right
        int ud[4] = {1, -1, 0, 0};  //up down
        for (int i=0; i<=rows+1; i++)
        {
            matrix[i][0] = '*';
            matrix[i][cols+1] = '*';
        }
        for (int i=1; i<=cols+1; i++)
        {
            matrix[0][i] = '*';
            matrix[rows+1][i] = '*';
        }
        for(int i=1; i<=rows; i++)
        {
            string rowIn;
            cin >> rowIn;
            for (int j=1; j<= cols; j++)
            {
                matrix[i][j] = rowIn[j-1];
            }
        }

        while(!bfsq.empty())
        {
            //cout << "hi";
            Node curr = bfsq.front();
            Coord currxy = curr.coord;
            if (currxy.x == endxy.x && currxy.y == endxy.y)
            {
                out.push_back(curr.level);
                break;
            }
            bfsq.pop();
            if (matrix[currxy.x][currxy.y] == '+')
            {
                for(int i=0; i<4; i++)
                {
                    int nextr = currxy.x + lr[i];
                    int nextc = currxy.y + ud[i];
                    if (visited[nextr][nextc] == 0 && matrix[nextr][nextc] != '*')
                    {
                        Coord nextCoord = {nextr, nextc};
                        Node nextNode = {nextCoord, curr.level + 1};
                        visited[nextr][nextc] = 1;
                        bfsq.push(nextNode);
                    }
                }
            }
            else if(matrix[currxy.x][currxy.y] == '|')
            {
                for(int i=0; i<2; i++)
                {
                    int nextr = currxy.x + ud[i];
                    int nextc = currxy.y;
                    if (visited[nextr][nextc] == 0 && matrix[nextr][nextc] != '*')
                    {
                        Coord nextCoord = {nextr, nextc};
                        Node nextNode = {nextCoord, curr.level + 1};
                        visited[nextr][nextc] = 1;
                        bfsq.push(nextNode);
                    }
                }
            }
            else if(matrix[currxy.x][currxy.y] == '-')
            {
                for(int i=2; i<4; i++)
                {
                    int nextr = currxy.x;
                    int nextc = currxy.y + lr[i];
                    if (visited[nextr][nextc] == 0 && matrix[nextr][nextc] != '*')
                    {
                        Coord nextCoord = {nextr, nextc};
                        Node nextNode = {nextCoord, curr.level + 1};
                        visited[nextr][nextc] = 1;
                        bfsq.push(nextNode);
                    }
                }
            }
        }
        if(bfsq.empty())
        {
            out.push_back(-1);
        }
        /*for(int i=1; i<=rows; i++)
        {
            for (int j=1; j<= cols; j++)
            {
                cout << matrix[i][j];
            }
            cout << '\n';
        }*/
    }
    for(int i=0; i<(int)out.size(); i++)
    {
        cout << out[i] << '\n';
    }
}
