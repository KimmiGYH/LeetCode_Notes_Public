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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        stack<TreeNode*> stk;
        if (!root) return 0;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* root = stk.top();
            stk.pop();
            if (root->left) {
                if (!root->left->left && !root->left->right)
                    res += root->left->val;
            }
            if (root->left) stk.push(root->left);
            if (root->right) stk.push(root->right);
        }
        return res;
    }
};