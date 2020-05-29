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

int main()
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = createTree(arr);
    display(root);
    cout << size(root) << endl;
    cout << height(root) << endl;
    return 0;
}