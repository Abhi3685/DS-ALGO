#include <iostream>
#include <vector>
using namespace std;

class Edge
{
public:
    int v;
    int w;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addEdge(vector<vector<Edge *>> &graph, int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w)); // For Bidirectional Graph
}

void removeEdge(vector<vector<Edge *>> &graph, int u, int v)
{
    vector<Edge *> edgesConnectedToU = graph[u];
    for (int i = 0; i < edgesConnectedToU.size(); i++)
    {
        if (edgesConnectedToU[i]->v == v)
        {
            edgesConnectedToU.erase(edgesConnectedToU.begin() + i);
            break;
        }
    }
    graph[u] = edgesConnectedToU;

    vector<Edge *> edgesConnectedToV = graph[v];
    for (int i = 0; i < edgesConnectedToV.size(); i++)
    {
        if (edgesConnectedToV[i]->v == u)
        {
            edgesConnectedToV.erase(edgesConnectedToV.begin() + i);
            break;
        }
    }
    graph[v] = edgesConnectedToV;
}

void removeVertex(vector<vector<Edge *>> &graph, int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        int v = graph[u][i]->v;
        removeEdge(graph, u, v);
    }
}

void display(vector<vector<Edge *>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i;
        for (Edge *e : graph[i])
        {
            cout << " -> " << e->v << ", " << e->w;
        }
        cout << endl;
    }
}

int main()
{
    int noOfVertices = 7;
    vector<vector<Edge *>> graph(noOfVertices, vector<Edge *>());

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 5, 4, 2);
    addEdge(graph, 5, 6, 3);
    addEdge(graph, 4, 6, 8);

    // removeEdge(graph, 4, 3);
    removeVertex(graph, 4);

    display(graph);

    return 0;
}