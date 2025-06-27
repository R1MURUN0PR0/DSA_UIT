#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

    map<int, int> topview;

    void view(Node* root) {
        if (root == NULL) return;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            Node* cur = q.front().fi;
            int pos = q.front().se; q.pop();
            if (topview.find(pos) == topview.end())
                topview[pos] = cur->data;
            if (cur->right)
                q.push({cur->right, pos - 1});
            if (cur->left)
                q.push({cur->left, pos + 1});
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    Solution myTree;
    Node* root = NULL;

    int t, data;
    cin >> t;
    
    while(t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.view(root);
    vector<int> res;
    for (auto& p : myTree.topview)
        res.push_back(p.se);

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}