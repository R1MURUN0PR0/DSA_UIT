#include <iostream>
using namespace std;

struct treenode
{
    int val;
    treenode *left;
    treenode *right;
    treenode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(treenode *node, int &count)
{
    if (!node)
        return 2; // Nếu node rỗng, coi như đã bị quan sát

    int left = dfs(node->left, count);
    int right = dfs(node->right, count);

    // Nếu cả hai node con đều không có camera và không bị quan sát
    if (left == 0 || right == 0)
    {
        count++;
        return 1; // Đặt camera
    }

    // Nếu một trong hai node con có camera
    if (left == 1 || right == 1)
        return 2; // Node này bị quan sát

    // Nếu cả hai node con đều bị quan sát
    return 0; // Node này không bị che khuất và không cần camera
}

int minCamera(treenode *root)
{
    int count = 0;
    if (dfs(root, count) == 0)
        count++; // Nếu root chưa được quan sát
    return count;
}

int main()
{
    int rootstart;
    cout << "Nhập giá trị gốc: ";
    cin >> rootstart;
    treenode *root = new treenode(rootstart);
    root->left = new treenode(2);
    root->left->left = new treenode(1);
    root->left->right = new treenode(5);
    root->left->right->left = new treenode(3);
    root->right = new treenode(10);
    root->right->left = new treenode(9);
    root->right->right = new treenode(12);
    root->right->right->right = new treenode(14);
    int count = minCamera(root);
    cout << count;

    return 0;
}