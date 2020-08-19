#include <bits/stdc++.h>

#include <cstdio>
#include <climits>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;    //using prims algorithm

struct Edge
{
    int pen = -1;
    int weight = 0;
};

Edge adjMat[1001][1001];
int matrix[101][101];
bool vis[101];

int prims(int size)
{
    memset(vis, false, sizeof(vis));
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	int mst = 0;
	int currNode = 0;
	vis[currNode] = true;
	int least = 0;

	for (int i = 0; i < size; i++)
	{
		if (matrix[currNode][i] != -1)
			pq.push({ matrix[currNode][i] ,i });
	}

	while (!pq.empty())
	{
		currNode = pq.top().second;
		least = pq.top().first;
		if(!vis[currNode])
        {
            mst += least;
            vis[currNode] = true;
        }
		pq.pop();
		for (int i = 0; i < size; i++)
		{
			if (matrix[currNode][i] != -1 && !vis[i])
				pq.push({ matrix[currNode][i] ,i });
		}
	}
	return mst;
}

int main()
{
    for (int j=0; j<101; j++)
        for(int i=0; i<101; i++)
        {
            matrix[i][j] = -1;
            matrix[i][i] = 0;
        }


    int m;
    scanf("%d", &m);
    for (int p=0; p<m; p++)
    {
        int nEdges;
        scanf("%d", &nEdges);
        int edges[nEdges+1];
        for(int i=0; i<nEdges; i++)
        {
            int vertice;
            scanf("%d", &vertice);
            edges[i] = vertice;
            if(i==0) edges[nEdges] = vertice;
        }
        for(int i=0; i<nEdges; i++)
        {
            int weight;
            scanf("%d", &weight);
            if(adjMat[edges[i]][edges[i+1]].weight > 0)
            {
                if(matrix[p][adjMat[edges[i]][edges[i+1]].pen] > weight || matrix[p][adjMat[edges[i]][edges[i+1]].pen] == -1)
                {
                    matrix[p][adjMat[edges[i]][edges[i+1]].pen] = weight;
                    matrix[adjMat[edges[i]][edges[i+1]].pen][p] = weight;
                }
                adjMat[edges[i]][edges[i+1]].pen = -1;
                adjMat[edges[i+1]][edges[i]].pen = -1;
            } else {
                adjMat[edges[i]][edges[i+1]].weight = weight;
                adjMat[edges[i+1]][edges[i]].weight = weight;
                adjMat[edges[i]][edges[i+1]].pen = p;
                adjMat[edges[i+1]][edges[i]].pen = p;
            }
        }
    }
    for(int i=0; i<1001; i++)
    {
        for(int j=0; j<1001; j++)
        {
            if(adjMat[i][j].pen >= 0 && (matrix[m][adjMat[i][j].pen] == -1 || matrix[m][adjMat[i][j].pen] > adjMat[i][j].weight))
            {
                matrix[m][adjMat[i][j].pen] = adjMat[i][j].weight;
                matrix[adjMat[i][j].pen][m] = adjMat[i][j].weight;
            }
        }
    }
    int b = prims(m+1);
    int a = prims(m);
    for(int i=0; i<m; i++)
    {
        if(vis[i] == false)
        {
            printf("%d", b);
            return 0;
        }
    }
    printf("%d", min(a, b));
    return 0;
    printf("\n");
    for(int i=0; i<=10; i++)
    {
        for(int j=0; j<=10; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}