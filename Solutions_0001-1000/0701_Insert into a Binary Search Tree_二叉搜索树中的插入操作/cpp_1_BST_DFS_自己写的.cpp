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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) return node;
        if (!root->left && val < root->val)
            root->left = node;
        else if (!root->right && val > root->val)
            root->right = node;
        
        if (val < root->val)
            insertIntoBST(root->left, val);
        else if (val > root->val)
            insertIntoBST(root->right, val);
        return root;
    }
};