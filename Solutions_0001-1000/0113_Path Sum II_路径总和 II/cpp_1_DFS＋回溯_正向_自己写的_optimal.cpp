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
    vector<int> path;
    vector<vector<int>> res;

    void dfs(TreeNode* root, int& targetSum, int sum) {
        path.push_back(root->val);
        if (!root->left && !root->right && targetSum == sum) {
            res.push_back(path);
        } else {
            if (root->left)
                dfs(root->left, targetSum, sum + root->left->val);
            if (root->right)
                dfs(root->right, targetSum, sum + root->right->val);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root)
            dfs(root, targetSum, root->val);
        return res;
    }
};