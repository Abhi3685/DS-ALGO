#include <iostream>
#include <algorithm>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 1;
        }
};

int height(Node* node){
    if(node == nullptr) return 0;
    return node->height;
}

int balfactor(Node* root) {
    if(root == nullptr) return 0;
    return height(root->left) - height(root->right);
}

Node* ll_rotate(Node* A) {
    Node* B = A->right;
    Node* tmp = B->left;

    B->left = A;
    A->right = tmp;

    return B;
}

Node* rr_rotate(Node* A) {
    Node* B = A->left;
    Node* tmp = B->right;

    B->right = A;
    A->left = tmp;

    return B;
}

Node* balance(Node* root) {
    int bal_factor = balfactor(root);
    if(bal_factor == 2){
        if(balfactor(root->left) == 1){ // RR Rotation
            root = rr_rotate(root);
        } else if(balfactor(root->left) == -1){ // RL Rotation
            root->left = ll_rotate(root->left);
            root = rr_rotate(root);
        }
    } else if(bal_factor == -2){
        if(balfactor(root->right) == 1){ // LR Rotation
            root->right = rr_rotate(root->right);
            root = ll_rotate(root);
        } else if(balfactor(root->right) == -1){ // LL Rotation
            root = ll_rotate(root);
        }
    }
    return root;
}

Node* insert(Node* root, int data) {
    if(root == nullptr){
        return new Node(data);
    }

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    root->height = 1 + max(height(root->left), height(root->right));
    return balance(root);
}

void display(Node* root) {
    if(root == nullptr) return;

    root->left != nullptr ? cout<<root->left->data : cout<<".";
    cout<<" => "<<root->data<<" <= ";
    root->right != nullptr ? cout<<root->right->data : cout<<".";
    cout<<endl;

    display(root->left);
    display(root->right);
}

int main()
{
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 19);
    root = insert(root, 30);
    root = insert(root, 27);
    root = insert(root, 16);

    display(root);

    return 0;
}