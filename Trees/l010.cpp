#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> childs;

    Node(int data)
    {
        this->data = data;
        this->childs = {};
    }
};

Node *createTree(vector<int> &arr)
{
    Node *root = nullptr;
    stack<Node *> st;
    for (int n : arr)
    {
        if (n == -1)
        {
            st.pop();
        }
        else
        {
            Node *node = new Node(n);
            if (st.empty())
            {
                root = node;
            }
            else
            {
                Node *par = st.top();
                par->childs.push_back(node);
            }
            st.push(node);
        }
    }
    return root;
}

void display(Node *root)
{
    cout << root->data << ": ";
    for (Node *child : root->childs)
    {
        cout << child->data << ", ";
    }
    cout << "." << endl;
    for (Node *child : root->childs)
    {
        display(child);
    }
}

int size(Node *root)
{
    int s = 0;

    for (Node *child : root->childs)
        s += size(child);

    return s + 1;
}

int height(Node *root)
{
    int h = -1;

    for (Node *child : root->childs)
        h = max(h, height(child));

    return h + 1;
}

bool find(Node *root, int data)
{
    if (root->data == data)
        return true;
    bool res = false;
    for (Node *child : root->childs)
    {
        res = res || find(child, data);
    }
    return res;
}

vector<int> rootToNodePath(Node *root, int data)
{
    if (root->data == data)
    {
        return {data};
    }
    for (Node *child : root->childs)
    {
        vector<int> res = rootToNodePath(child, data);
        if (res.size() > 0)
        {
            res.push_back(root->data);
            return res;
        }
    }
    return {};
}

bool isMirror(Node *root1, Node *root2)
{
    if (root1->data != root2->data)
        return false;

    for (int i = 0, j = root2->childs.size() - 1; i <= j; i++, j--)
    {
        if (!isMirror(root1->childs[i], root2->childs[j]))
            return false;
    }
    return true;
}

int main()
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = createTree(arr);
    // display(root);
    cout << size(root) << endl;
    cout << height(root) << endl;
    cout << find(root, 80) << endl;
    vector<int> ans = rootToNodePath(root, 80);
    for (int n : ans)
        cout << n << " ";
    cout << endl;
    cout << isMirror(root, root) << endl;
    return 0;
}