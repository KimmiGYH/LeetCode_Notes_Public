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
    bool dfs(TreeNode* root, int& targetSum, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right) {
            if (sum == targetSum)
                return true;
            else
                return false;
        }
        if (root->left)
            if (dfs(root->left, targetSum, sum + root->left->val))
                return true;
        if (root->right)
            if (dfs(root->right, targetSum, sum + root->right->val))
                return true;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        bool res = dfs(root, targetSum, root->val);
        return res;
    }
};