#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits.h>
using namespace std;

class Edge
{
public:
    int v = 0; // vertex
    int w = 0; // weight

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int n = 7;
vector<vector<Edge *>> graph(n, vector<Edge *>());

void addEdge(int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

int getMinDistNodeIdx(vector<int> &distances, vector<bool> &visited)
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < graph.size(); v++)
        if (!visited[v] && distances[v] <= min)
        {
            min = distances[v];
            min_index = v;
        }
    return min_index;
}

void dijikstraAlgo(int src)
{
    vector<bool> visited(n, false);
    vector<int> distances(n, INT_MAX);
    distances[src] = 0;

    for (int u = 0; u < graph.size(); u++)
    {
        int pickedVtx = getMinDistNodeIdx(distances, visited);
        visited[pickedVtx] = true;
        for (Edge *e : graph[pickedVtx])
            if (!visited[e->v] && distances[pickedVtx] + e->w < distances[e->v])
                distances[e->v] = distances[pickedVtx] + e->w;
    }

    cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < graph.size(); i++)
        cout << i << " \t\t " << distances[i] << "\n";
}

int main()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(3, 2, 40);
    addEdge(3, 4, 20);
    addEdge(4, 5, 20);
    addEdge(4, 6, 50);
    addEdge(5, 6, 80);

    dijikstraAlgo(0);
    return 0;
}