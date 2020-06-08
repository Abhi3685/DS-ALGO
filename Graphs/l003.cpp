#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}

void addEdge2(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool isCyclicDirectedGraph(vector<vector<int>> &graph, int i, vector<bool> &visited, vector<bool> &recStack)
{
    visited[i] = true;
    recStack[i] = true;

    for (int c : graph[i])
    {
        if (!visited[c])
        {
            if (isCyclicDirectedGraph(graph, c, visited, recStack))
                return true;
        }
        else if (recStack[c])
            return true;
    }

    recStack[i] = false;
    return false;
}

bool isCyclicUndirectedGraph(vector<vector<int>> &graph, int i, vector<bool> &visited, int parent)
{
    visited[i] = true;

    for (int c : graph[i])
    {
        if (!visited[c])
        {
            if (isCyclicUndirectedGraph(graph, c, visited, i))
                return true;
        }
        else if (c != parent)
            return true;
    }

    return false;
}

int main()
{
    int noOfVertices = 4;
    vector<vector<int>> graph(noOfVertices, vector<int>());

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);

    vector<bool> visited(noOfVertices, false);
    vector<bool> recStack(noOfVertices, false);
    bool ans = isCyclicDirectedGraph(graph, 0, visited, recStack);
    if (ans)
        cout << "Cycle Found!" << endl;
    else
        cout << "No Cycle Found!" << endl;

    // =======================================

    int noOfVertices2 = 5;
    vector<vector<int>> graph2(noOfVertices2, vector<int>());

    addEdge2(graph2, 1, 0);
    addEdge2(graph2, 0, 2);
    addEdge2(graph2, 2, 1);
    addEdge2(graph2, 0, 3);
    addEdge2(graph2, 3, 4);

    vector<bool> visited2(noOfVertices2, false);
    bool ans2 = isCyclicUndirectedGraph(graph2, 0, visited2, -1);
    if (ans2)
        cout << "Cycle Found!" << endl;
    else
        cout << "No Cycle Found!" << endl;

    return 0;
}