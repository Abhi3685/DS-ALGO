#include <iostream>
#include <vector>
#include <string>
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

void DFS(vector<vector<Edge *>> &graph, int u, vector<bool> &vis)
{
    cout << u << " ";
    vis[u] = true;
    for (Edge *e : graph[u])
    {
        if (!vis[e->v])
        {
            DFS(graph, e->v, vis);
        }
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

bool hasPath(vector<vector<Edge *>> &graph, int src, int dest, string ans, vector<bool> &vis)
{
    if (src == dest)
    {
        cout << ans + to_string(src) << endl;
        return true;
    }
    vis[src] = true;
    bool res = false;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            res = res || hasPath(graph, e->v, dest, ans + to_string(src) + " ", vis);
    }
    return res;
}

int allPath(vector<vector<Edge *>> &graph, int src, int dest, string ans, vector<bool> &vis)
{
    if (src == dest)
    {
        cout << ans + to_string(dest) << endl;
        return 1;
    }
    vis[src] = true;
    int count = 0;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            count += allPath(graph, e->v, dest, ans + to_string(src) + " ", vis);
    }
    vis[src] = false;
    return count;
}

int hamiltonianPath(vector<vector<Edge *>> &graph, int src, string ans, vector<bool> &vis)
{
    if (ans.length() == graph.size())
    {
        cout << ans << endl;
        return 1;
    }
    vis[src] = true;
    int count = 0;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            count += hamiltonianPath(graph, e->v, ans + to_string(e->v), vis);
    }
    vis[src] = false;
    return count;
}

int hamiltonianCycle(vector<vector<Edge *>> &graph, int src, string ans, vector<bool> &vis)
{
    if (ans.length() == graph.size())
    {
        int fv = ans[0] - '0';                // Starting Vertex
        int lv = ans[graph.size() - 1] - '0'; // Ending Vertex
        // check if edge exists from first to last vertex in hamiltonian path
        for (Edge *e : graph[fv])
        {
            if (e->v == lv)
            {
                cout << ans + to_string(fv) << endl;
                return 1;
            }
        }
        return 0;
    }
    vis[src] = true;
    int count = 0;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            count += hamiltonianCycle(graph, e->v, ans + to_string(e->v), vis);
    }
    vis[src] = false;
    return count;
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
    // removeVertex(graph, 4);

    // display(graph);

    vector<bool> vis(noOfVertices);
    // DFS(graph, 0, vis);

    // hasPath(graph, 0, 6, "", vis);
    // allPath(graph, 0, 6, "", vis);

    // hamiltonianPath(graph, 0, "0", vis);

    // addEdge(graph, 5, 2, 5);
    // hamiltonianCycle(graph, 0, "0", vis);

    return 0;
}