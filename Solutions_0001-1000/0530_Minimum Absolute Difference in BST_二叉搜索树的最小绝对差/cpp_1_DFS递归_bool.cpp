/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = INT_MAX;
    int last;
    bool is_first = true;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        
        if (is_first)
            is_first = false;
        else
            res = min(res, root->val - last);
        last = root->val;

        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return res;
    }
};