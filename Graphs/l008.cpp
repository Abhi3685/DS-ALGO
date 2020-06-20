#include <iostream>
#include <vector>
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

int n = 10; // number of vertex
vector<vector<Edge *>> graph(n, vector<Edge *>());

void addEdge(int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

int timer = 0;
void APUtil(int u, vector<int> &parent, vector<int> &lowest, vector<int> &discovery, vector<bool> &visited, vector<bool> &AP)
{
    visited[u] = true;
    int children = 0;
    discovery[u] = lowest[u] = ++timer;

    for (Edge *e : graph[u])
    {
        if (!visited[e->v])
        {
            children++;
            parent[e->v] = u;
            APUtil(e->v, parent, lowest, discovery, visited, AP);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            lowest[u] = min(lowest[u], lowest[e->v]);

            // u is an articulation point in following cases

            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == -1 && children > 1)
                AP[u] = true;

            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != -1 && lowest[e->v] >= discovery[u])
                AP[u] = true;
        }
        else if (e->v != parent[u])
            lowest[u] = min(lowest[u], discovery[e->v]);
    }
}

void ABUtil(int u, vector<int> &parent, vector<int> &lowest, vector<int> &discovery, vector<bool> &visited)
{
    visited[u] = true;
    discovery[u] = lowest[u] = ++timer;

    for (Edge *e : graph[u])
    {
        if (!visited[e->v])
        {
            parent[e->v] = u;
            ABUtil(e->v, parent, lowest, discovery, visited);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            lowest[u] = min(lowest[u], lowest[e->v]);

            // If the lowest vertex reachable from subtree
            // under v is  below u in DFS tree, then u-v
            // is a bridge
            if (lowest[e->v] > discovery[u])
                cout << u << " " << e->v << endl;
        }
        else if (e->v != parent[u])
            lowest[u] = min(lowest[u], discovery[e->v]);
    }
}

void ArticulationPoint()
{
    vector<int> parent(n, -1);
    vector<int> discovery(n);
    vector<int> lowest(n);
    vector<bool> visited(n, false);
    vector<bool> AP(n, false);
    timer = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            APUtil(i, parent, lowest, discovery, visited, AP);

    cout << "Articulation points are: " << endl;
    for (int i = 0; i < n; i++)
        if (AP[i] == true)
            cout << i << " ";
}

void ArticulationBridge()
{
    vector<int> parent(n, -1);
    vector<int> discovery(n);
    vector<int> lowest(n);
    vector<bool> visited(n, false);
    timer = 0;

    cout << "Articulation Bridges are: " << endl;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            ABUtil(i, parent, lowest, discovery, visited);
}

void solve()
{
    addEdge(0, 1, 1);
    addEdge(1, 2, 1);
    addEdge(2, 3, 1);
    addEdge(3, 0, 1);
    addEdge(3, 5, 1);
    addEdge(5, 4, 1);
    addEdge(5, 6, 1);
    addEdge(4, 0, 1);
    addEdge(2, 7, 1);
    addEdge(7, 8, 1);
    addEdge(7, 9, 1);
    addEdge(8, 9, 1);

    ArticulationPoint();
    cout << endl;
    ArticulationBridge();
}

int main()
{
    solve();
    return 0;
}