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
    bool check = false;

    bool dfs(TreeNode* root, int& targetSum, int sum) {
        path.push_back(root->val);
        if (!root->left && !root->right && sum == targetSum) {
            res.push_back(path);
            check = true;
        }
            
        if (root->left) {
            if (dfs(root->left, targetSum, sum + root->left->val)) {
                check = true;
                path.push_back(root->left->val);
            }
            path.pop_back();
        }

        if (root->right) {
            if (dfs(root->right, targetSum, sum + root->right->val)) {
                check = true;
                path.push_back(root->right->val);
            }
            path.pop_back();
        }
        return false;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        dfs(root, targetSum, root->val);
        return res;
    }
};