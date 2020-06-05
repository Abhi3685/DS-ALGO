#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

int n = 7; // number of vertex
vector<vector<Edge *>> graph(n, vector<Edge *>());

void addEdge(int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w)); // Directed Graph
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (Edge *e : graph[i])
        {
            cout << "(" << e->v << ", " << e->w << ") ";
        }
        cout << endl;
    }
}

void topologicalSort(int v, vector<bool> &vis, stack<int> &st)
{
    vis[v] = true;
    for (Edge *e : graph[v])
    {
        if (vis[e->v] == false)
            topologicalSort(e->v, vis, st);
    }
    st.push(v);
}

void BFS(int vtx, int data, vector<bool> &vis)
{
    queue<int> q;
    q.push(vtx);
    vis[vtx] = true;

    while (q.size() != 0)
    {
        int rvtx = q.front();
        // cout << rvtx << " ";
        q.pop();

        // Condition to check if given data exist in graph.
        // if (rvtx == data)
        // {
        //     cout << data << " found in graph.";
        //     continue;
        // }

        // Condition to check if cycle exists in graph.
        if (vis[rvtx])
        {
            cout << "Cycle Found!" << endl;
            continue; // Comment for all possible cycles
        }

        for (Edge *e : graph[rvtx])
        {
            if (!vis[e->v])
            {
                vis[e->v] = true;
                q.push(e->v);
            }
        }
    }
}

void GCC()
{
    vector<bool> vis(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            BFS(i, 0, vis);
            count++;
        }
    }
    cout << "GCC: " << count << endl;
}

int main()
{
    // Create directed graph
    addEdge(0, 1, 5);
    addEdge(0, 3, 5);
    addEdge(3, 2, 5);
    addEdge(2, 1, 5);
    addEdge(1, 4, 5);
    addEdge(4, 5, 5);
    addEdge(4, 6, 5);
    addEdge(5, 6, 5);

    // display();

    // ============ Topological Sort ============
    // vector<bool> vis(n, false);
    // stack<int> st;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!vis[i])
    //         topologicalSort(0, vis, st);
    // }
    // // Print stack
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    // ============ BFS (Breadth First Search) ============
    vector<bool> vis(n, false);
    BFS(0, 5, vis);

    // Get Connected Components (GCC)
    // Output: 1 for given graph
    // Comment edge between 1 and 4 to get output as 2
    GCC();

    return 0;
}