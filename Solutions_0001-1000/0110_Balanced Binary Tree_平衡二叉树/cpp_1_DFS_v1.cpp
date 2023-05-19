#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool ans = true;
        dfs(root, &ans); // &取地址符
        return ans;        
    }

    int dfs(TreeNode* root, bool* ans) { // * 指针
        if (!root)  return 0;
        int lh = dfs(root->left, ans), rh = dfs(root->right, ans);
        if (abs(lh - rh) > 1)  *ans = false; // * 解引用符
        return max(lh, rh) + 1;
    }
};