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

void flatten(Node *root)
{
    vector<Node *> newChilds;
    for (Node *child : root->childs)
    {
        flatten(child);
        newChilds.push_back(child);
        for (Node *childOfChild : child->childs)
        {
            newChilds.push_back(childOfChild);
        }
        child->childs.clear();
    }
    root->childs.clear();
    root->childs = newChilds;
}

Node *linearize(Node *root)
{
    if (root->childs.size() == 0)
        return root;

    Node *lastTail = linearize(root->childs[root->childs.size() - 1]);
    for (int i = root->childs.size() - 2; i >= 0; i--)
    {
        Node *secondLastTail = linearize(root->childs[i]);
        secondLastTail->childs.push_back(root->childs[i + 1]);
        root->childs.pop_back();
    }
    return lastTail;
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

int main()
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = createTree(arr);

    // flatten(root);
    // for (Node *child : root->childs)
    // {
    //     cout << child->data << " ";
    // }
    // cout << endl;

    linearize(root);
    display(root);

    return 0;
}