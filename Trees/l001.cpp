#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void preOrder(Node *node)
{
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node)
{
    if (node == nullptr)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node *node)
{
    if (node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

void display(Node *node)
{
    if (node == nullptr)
        return;

    string str;
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " -> " + to_string(node->data) + " <- ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

int idx = 0;
Node *createFromArr(vector<int> &arr)
{
    if (arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    if (idx >= arr.size())
        return nullptr;

    Node *node = new Node(arr[idx]);
    idx++;
    node->left = createFromArr(arr);
    node->right = createFromArr(arr);

    return node;
}

int height(Node *root)
{
    if (root == nullptr)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

int size(Node *root)
{
    if (root == nullptr)
        return 0;

    return size(root->left) + size(root->right) + 1;
}

bool find(Node *root, int data)
{
    if (root == nullptr)
        return false;
    if (root->data == data)
        return true;

    return find(root->left, data) || find(root->right, data);
}

vector<int> rootToNodePath(Node *root, int data)
{
    if (root == nullptr)
        return {};
    if (root->data == data)
        return {data};

    vector<int> left = rootToNodePath(root->left, data);
    if (left.size() != 0)
    {
        left.push_back(root->data);
        return left;
    }
    vector<int> right = rootToNodePath(root->right, data);
    if (right.size() != 0)
    {
        right.push_back(root->data);
        return right;
    }

    return {};
}

int LowestCommonAncestor(Node *root, int data1, int data2)
{
    vector<int> path1 = rootToNodePath(root, data1);
    vector<int> path2 = rootToNodePath(root, data2);

    int lca = 0;
    for (int i = path1.size() - 1, j = path2.size() - 1; i >= 0, j >= 0; i--, j--)
    {
        if (path1[i] == path2[j])
        {
            lca = path1[i];
        }
        else
            break;
    }
    return lca;
}

int diameter(Node *root)
{
    if (root == nullptr)
        return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

void isBST(Node *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    isBST(root->left, ans);
    ans.push_back(root->data);
    isBST(root->right, ans);
}

int main()
{
    // Creating Tree
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->left->left = new Node(40);
    // root->left->right = new Node(50);
    // root->right->left = new Node(60);
    // root->right->right = new Node(70);

    // Tree Traversals
    // preOrder(root);
    // inOrder(root);
    // postOrder(root);

    vector<int> arr = {50, 20, 10, -1, -1, 30, -1, -1, 80, 70, -1, -1, 90, -1, -1};
    Node *root = createFromArr(arr);

    // display(root);
    // cout << height(root) << endl;
    // cout << size(root) << endl;
    // cout << find(root, 80) << endl;

    // vector<int> path = rootToNodePath(root, 30);
    // for (int p : path)
    //     cout << p << " ";
    // cout << endl;

    // cout << LowestCommonAncestor(root, 20, 60) << endl;
    // cout << diameter(root) << endl;

    // vector<int> ans;
    // isBST(root, ans);
    // int i;
    // for (i = 1; i < ans.size(); i++)
    //     if (ans[i] <= ans[i - 1])
    //     {
    //         break;
    //     }
    // i == ans.size() ? cout << true << endl : cout << false << endl;

    return 0;
}