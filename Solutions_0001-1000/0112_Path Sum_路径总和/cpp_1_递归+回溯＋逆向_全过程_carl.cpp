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
    bool dfs(TreeNode* root, int count) {
        if (!root->left && !root->right && count == 0)
            return true;
        if (!root->left && !root->right)
            return false;
        
        if (root->left) {
            count -= root->left->val;
            if (dfs(root->left, count)) return true;
            count += root->left->val;
        }
        if (root->right) {
            count -= root->right->val;
            if (dfs(root->right, count)) return true;
            count += root->right->val;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, targetSum - root->val);
    }
};

// =========== 简化为 ===========

class Solution {
public:
    bool dfs(TreeNode* root, int count) {
        if (!root->left && !root->right && count == 0)
            return true;
        if (!root->left && !root->right)
            return false;
        
        if (root->left)
            if (dfs(root->left, count - root->left->val))
                return true;
        if (root->right)
            if (dfs(root->right, count - root->right->val))
                return true;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, targetSum - root->val);
    }
};