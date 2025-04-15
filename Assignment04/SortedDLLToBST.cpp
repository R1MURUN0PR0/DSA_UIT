#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* sortedDLLToBST(Node* &head, int n) {
    if (n <= 0) return nullptr;

    Node* left = sortedDLLToBST(head, n / 2);
    Node* root = new Node(head->data);
    root->left = left;
    head = head->right;
    root->right = sortedDLLToBST(head, n - n / 2 - 1);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}