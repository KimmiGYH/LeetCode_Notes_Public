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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        if (!root) return nullptr;
        stk.push(root);
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            swap(t->left, t->right);
            if (t->right)
                stk.push(t->right);
            if (t->left)
                stk.push(t->left);
        }
        return root;
    }
};