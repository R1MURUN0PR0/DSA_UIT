struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* BSTToSortedDLL(Node* root) {
    Node* curr = root;
    Node* prev = nullptr;
    Node* final_head = nullptr;

    while (curr) {
        if (!curr->left) {
            if (!final_head) {
                final_head = curr;
            }
            prev = curr;
            curr = curr->right;
        } else {
            Node* pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
                prev->right = curr;
                curr->left = prev;
                prev = curr;
                curr = curr->right;
            }
        }
    }

    return final_head;
}