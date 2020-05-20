#include <iostream>
#include <vector>
#include <unordered_map>
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

int maxLevel = -1;
void leftView(Node *root, int level)
{
    if (root == nullptr)
        return;

    if (level > maxLevel)
    {
        maxLevel = level;
        cout << root->data << " ";
    }

    leftView(root->left, level + 1);
    leftView(root->right, level + 1);
}

void rightView(Node *root, int level)
{
    if (root == nullptr)
        return;

    if (level > maxLevel)
    {
        maxLevel = level;
        cout << root->data << " ";
    }

    rightView(root->right, level + 1);
    rightView(root->left, level + 1);
}

void leftExceptLeaf(Node *root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    cout << root->data << " ";
    leftExceptLeaf(root->left);
}

void onlyLeaves(Node *root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->data << " ";
        return;
    }
    onlyLeaves(root->left);
    onlyLeaves(root->right);
}

void rightExceptLeaf(Node *root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    rightExceptLeaf(root->right);
    cout << root->data << " ";
}

void boundaryView(Node *root)
{
    leftExceptLeaf(root);
    onlyLeaves(root);
    rightExceptLeaf(root->right);
}

unordered_map<int, vector<int>> map;
int minLevel_ = (int)1e8, maxLevel_ = (int)-1e8;
void verticalOrder(Node *root, int level)
{
    if (root == nullptr)
        return;

    if (level < minLevel_)
        minLevel_ = level;
    if (level > maxLevel_)
        maxLevel_ = level;

    if (map.count(level) != 0)
        map[level].push_back(root->data);
    else
        map[level] = {root->data};
    verticalOrder(root->left, level - 1);
    verticalOrder(root->right, level + 1);
}

int main()
{
    vector<int> arr = {10, 15, 10, 9, -1, -1, 13, -1, -1, 20, 28, -1, -1, 48, -1, -1, 16, 12, -1, -1, 18, -1, -1};
    Node *root = createFromArr(arr);

    // leftView(root, 0);

    // rightView(root, 0);

    // boundaryView(root);

    // verticalOrder(root, 0);
    // for (int i = minLevel_; i <= maxLevel_; i++)
    // {
    //     for (int n : map[i])
    //         cout << n << " ";
    //     cout << endl;
    // }

    return 0;
}