#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
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

class BSTPair
{
public:
    bool isBST = true;
    int count = 0;

    int max_ = (int)-1e8;
    int min_ = (int)1e8;
};

BSTPair BSTSolution(Node *root)
{
    if (root == nullptr)
        return BSTPair();

    BSTPair leftAns = BSTSolution(root->left);
    BSTPair rightAns = BSTSolution(root->right);

    BSTPair myAns;
    if (leftAns.isBST && rightAns.isBST && root->data > leftAns.max_ && root->data < rightAns.min_)
    {
        myAns.isBST = true;
        myAns.count = leftAns.count + rightAns.count + 1;
    }
    else
    {
        myAns.isBST = false;
        myAns.count = leftAns.count + rightAns.count;
    }

    myAns.min_ = min(min(leftAns.min_, rightAns.min_), root->data);
    myAns.max_ = max(max(leftAns.max_, rightAns.max_), root->data);
    return myAns;
}

int height(Node *root)
{
    if (root == nullptr)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node *root)
{
    if (root == nullptr)
        return true;

    bool isLeftBalanced = isBalanced(root->left);
    bool isRightBalanced = isBalanced(root->right);

    int lh = height(root->left);
    int rh = height(root->right);

    return isLeftBalanced && isRightBalanced && abs(lh - rh) <= 1;
}

Node *linearTree(Node *root)
{
    if (root == nullptr)
        return nullptr;
    if (root->left == nullptr && root->right == nullptr)
        return root;

    Node *leftTail = linearTree(root->left);
    Node *rightTail = linearTree(root->right);

    if (leftTail != nullptr)
        leftTail->left = root->right;
    else
        root->left = root->right;
    root->right = nullptr;

    return rightTail != nullptr ? rightTail : leftTail;
}

Node *head = nullptr, *prevNode = nullptr;
void convertToDLL(Node *node)
{
    if (node == nullptr)
        return;
    convertToDLL(node->left);
    if (prevNode == nullptr)
        head = node;
    else
    {
        node->left = prevNode;
        prevNode->right = node;
    }
    prevNode = node;
    convertToDLL(node->right);
}

int main()
{
    vector<int> arr = {10, 15, 10, 9, -1, -1, 13, -1, -1, 20, 28, -1, -1, 48, -1, -1, 16, 12, -1, -1, 18, -1, -1};
    Node *root = createFromArr(arr);

    // BSTPair b = BSTSolution(root);
    // cout << b.isBST << " " << b.count << endl;

    // cout << isBalanced(root) << endl;

    // linearTree(root);
    // display(root);

    convertToDLL(root);
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->right;
    }

    return 0;
}