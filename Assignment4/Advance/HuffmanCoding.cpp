#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
    Node(int f, Node* l, Node* r) {
        ch = 0;
        freq = f;
        left = l, right = r;
    }
};

struct comp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void build(Node* node, string bin, unordered_map<char, string>& binMp) {
    if (!node) return;
    if (node->left == NULL && node->right == NULL) {
        if (bin == "") bin = "0"; 
        binMp[node->ch] = bin;
        return;
    }
    build(node->left, bin + "0", binMp);
    build(node->right, bin + "1", binMp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
    int n;              
    string s;        
    cin >> n >> s;

    unordered_map<char, int> freqMap;
    for (char c : s) freqMap[c]++;

    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto it : freqMap) pq.push(new Node(it.fi, it.se));

    if (pq.size() == 1) {
        Node* uniq = pq.top();
        cout << uniq->freq << endl; 
        return 0;
    }
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();   
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node(left->freq + right->freq, left, right);
        pq.push(parent); 
    }

    Node* root = pq.top();
    unordered_map<char, string> binMp;
    build(root, "", binMp);

    int res = 0;
    for (char c : s) res += binMp[c].length();
    cout << res << endl;

    return 0;
}