#include <iostream>
#include <vector>
#include <string>
#include <queue>
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

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (q.size() != 0)
    {
        int size = q.size();
        cout << "Level " << i++ << ": ";
        while (size-- > 0)
        {
            Node *node = q.front();
            q.pop();

            cout << node->data << " ";

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        cout << endl;
    }
    cout << endl;
}

void kaway(Node* node, int k, Node* rNode){
    if(node == nullptr) return;
    if(node == rNode) return;
    if(k == 0){
        cout<<node->data<<" ";
        return;
    }

    kaway(node->left, k-1, rNode);
    kaway(node->right, k-1, rNode);
}

vector<Node*> rootToNodePath(Node *root, int data)
{
    if (root == nullptr)
        return {};
    if (root->data == data)
        return {root};

    vector<Node*> left = rootToNodePath(root->left, data);
    if (left.size() != 0)
    {
        left.push_back(root);
        return left;
    }
    vector<Node*> right = rootToNodePath(root->right, data);
    if (right.size() != 0)
    {
        right.push_back(root);
        return right;
    }

    return {};
}

void kfar(Node* node, int k, int data){
    vector<Node*> path = rootToNodePath(node, data);
    Node* rNode = nullptr;
    for(int i = 0; i < path.size(); i++){
        kaway(path[i], k - i, rNode);
        rNode = path[i];
    }
}

int main()
{
    vector<int> arr = {50, 20, 10, -1, -1, 30, -1, -1, 80, 70, -1, -1, 90, -1, -1};
    Node *root = createFromArr(arr);

    // display(root);

    // levelOrder(root);
    // kaway(root, 1, nullptr);
    kfar(root, 1, 20);

    return 0;
}