#include <iostream>
#include <stack>
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

void iterativePreorder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (s.size() != 0)
    {
        Node *tmp = s.top();
        cout << tmp->data << " ";
        s.pop();

        if (tmp->right != nullptr)
            s.push(tmp->right);
        if (tmp->left != nullptr)
            s.push(tmp->left);
    }
    cout << endl;
}

void morrisInorder(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *tmp = curr->left;
            while (tmp->right != nullptr && tmp->right != curr)
                tmp = tmp->right;

            if (tmp->right == nullptr)
            {
                tmp->right = curr;
                curr = curr->left;
            }
            else
            {
                tmp->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

void iterativePostorder(Node *root)
{
    stack<Node *> s1, s2;
    s1.push(root);

    while (s1.size() != 0)
    {
        Node *tmp = s1.top();
        s1.pop();
        s2.push(tmp);

        if (tmp->left != nullptr)
            s1.push(tmp->left);
        if (tmp->right != nullptr)
            s1.push(tmp->right);
    }

    while (s2.size() != 0)
    {
        Node *tmp = s2.top();
        s2.pop();
        cout << tmp->data << " ";
    }

    cout << endl;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    iterativePreorder(root);
    morrisInorder(root);
    iterativePostorder(root);

    return 0;
}