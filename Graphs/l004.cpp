#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}

void topoSort(vector<vector<int>> &graph)
{
    vector<int> in_degree(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        for (int v : graph[i])
            in_degree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < graph.size(); i++)
        if (in_degree[i] == 0)
            q.push(i);

    vector<int> top_order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for (int nbr : graph[u])
            if (--in_degree[nbr] == 0)
                q.push(nbr);
    }

    if (top_order.size() != graph.size())
    {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}

int main()
{
    int noOfVertices = 4;
    vector<vector<int>> graph(noOfVertices, vector<int>());

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    // addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);

    topoSort(graph);

    return 0;
}