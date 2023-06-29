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
    TreeNode* parent;

    void dfs(TreeNode* cur, int& val) {
        if (!cur) {
            TreeNode* node = new TreeNode(val);
            if (val < parent->val)
                parent->left = node;
            else
                parent->right = node;
            return;
        }
        parent = cur;
        if (val < cur->val) dfs(cur->left, val);
        if (val > cur->val) dfs(cur->right, val);
        return;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        parent = new TreeNode(0);
        if (!root)
            return new TreeNode(val);
        dfs(root, val);
        return root;
    }
};