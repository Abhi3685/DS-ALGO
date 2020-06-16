#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findParent(int vtx, vector<int> &parent)
{
    if (parent[vtx] == vtx)
        return vtx;

    return parent[vtx] = findParent(parent[vtx], parent);
}

void merge(int p1, int p2, vector<int> &parent, vector<int> &size)
{
    if (size[p1] < size[p2])
    {
        parent[p1] = p2;
        size[p2] += size[p1];
    }
    else
    {
        parent[p2] = p1;
        size[p1] += size[p2];
    }
}

void DSU()
{
    vector<vector<int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 3});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    // edges.push_back({3, 4});
    edges.push_back({4, 5});
    edges.push_back({4, 6});
    edges.push_back({5, 6});

    int n = 7;
    vector<int> parent(n);
    vector<int> size(n, 1);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (vector<int> edge : edges)
    {
        int u = edge[0], v = edge[1];
        int p1 = findParent(u, parent);
        int p2 = findParent(v, parent);

        if (p1 != p2)
            merge(p1, p2, parent, size);
        else
            cout << "Cycle Detected with edge from " << u << " to " << v << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> parent: " << parent[i] << endl;
    }
}

void kruskalAlgo()
{
    vector<vector<int>> edges;
    vector<vector<int>> result;
    edges.push_back({0, 1, 10}); // u, v, w
    edges.push_back({0, 3, 10});
    edges.push_back({1, 2, 10});
    edges.push_back({2, 3, 40});
    edges.push_back({3, 4, 2});
    edges.push_back({4, 5, 2});
    edges.push_back({4, 6, 8});
    edges.push_back({5, 6, 3});

    sort(edges.begin(), edges.end(), [](const vector<int> &v1, const vector<int> &v2) {
        return v1[2] < v2[2];
    });

    int n = 7;
    vector<int> parent(n);
    vector<int> size(n, 1);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        int p1 = findParent(u, parent);
        int p2 = findParent(v, parent);

        if (p1 != p2)
        {
            result.push_back(edge);
            merge(p1, p2, parent, size);
        }
    }

    for (auto res : result)
    {
        cout << res[0] << " " << res[1] << " " << res[2] << endl;
    }
}

int main()
{
    // DSU();
    kruskalAlgo();
    return 0;
}