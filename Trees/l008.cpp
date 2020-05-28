#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int cameras = 0;
int binaryTreeCameraUtil(Node *root)
{
    if (root == nullptr)
        return 0;

    int left = binaryTreeCameraUtil(root->left);
    int right = binaryTreeCameraUtil(root->right);

    if (root->left == nullptr && root->right == nullptr)
        return -1;

    if (left == -1 || right == -1)
    {
        cameras++;
        return 1;
    }
    if (left == 1 || right == 1)
        return 0;

    return -1;
}

void binaryTreeCamera(Node *root)
{
    // 3 Cases:
    // 1. I need a camera -> -1
    // 2. I am a camera -> 1
    // 3. I am covered -> 0

    int ans = binaryTreeCameraUtil(root);
    if (ans == -1)
        cameras++;
    cout << cameras << endl;
}

int main()
{
    Node *root = new Node(0);
    root->left = new Node(0);
    root->left->left = new Node(0);
    root->left->left->left = new Node(0);
    root->left->left->left->right = new Node(0);

    binaryTreeCamera(root);

    return 0;
}