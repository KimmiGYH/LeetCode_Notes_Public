#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            auto cur = new TreeNode(v);
            cur->left = root;
            return cur;
        }
        dfs(root, v, d, 1);
        return root;
    }
    
    void dfs(TreeNode* root, int& v, int& d, int u) {
        if (root == nullptr) return;
        if (u == d - 1) {
            auto l = new TreeNode(v), r = new TreeNode(v);
            l->left = root->left, r->right = root->right;
            root->left = l, root->right = r;
        }
        dfs(root->left, v, d, u + 1);
        dfs(root->right, v, d, u + 1);
    }
};