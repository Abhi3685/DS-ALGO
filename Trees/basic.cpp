#include <iostream>
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

    // display(root);
    return 0;
}