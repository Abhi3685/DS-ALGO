#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}

bool bipartite(vector<vector<int>> &graph, int src, vector<int> &vis)
{
    queue<pair<int, int>> que;
    que.push({src, 0});
    while (que.size() != 0)
    {
        pair<int, int> rpair = que.front();
        que.pop();

        int u = rpair.first, c = rpair.second;
        if (vis[u] != -1)
        {
            if (vis[u] != c)
                return false;
            else
                continue;
        }
        vis[u] = c;

        for (int nbr : graph[u])
        {
            if (vis[nbr] == -1)
                que.push({nbr, (c + 1) % 2});
        }
    }
    return true;
}

int main()
{
    int noOfVertices = 7;
    vector<vector<int>> graph(noOfVertices, vector<int>());

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 1, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);

    vector<int> vis(noOfVertices, -1);
    for (int i = 0; i < noOfVertices; i++)
    {
        if (vis[i] == -1)
            if (!bipartite(graph, i, vis))
            {
                cout << "Graph Not Bipartite!";
                break;
            }
    }

    return 0;
}