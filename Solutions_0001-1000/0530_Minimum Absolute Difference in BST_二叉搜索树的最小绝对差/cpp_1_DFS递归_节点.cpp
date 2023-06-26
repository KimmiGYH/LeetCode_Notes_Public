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
    int diff = INT_MAX;
    TreeNode* pre = NULL;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        
        if (pre != NULL)
            diff = min(diff, root->val - pre->val);
        pre = root;
        
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return diff;
    }
};