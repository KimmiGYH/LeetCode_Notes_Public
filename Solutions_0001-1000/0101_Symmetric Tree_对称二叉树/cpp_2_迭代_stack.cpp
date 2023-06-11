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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> stk;
        stk.push(root->left);
        stk.push(root->right);
        while (!stk.empty()) {
            auto p = stk.top(); stk.pop();
            auto q = stk.top(); stk.pop();
            if (!p && !q) continue; // continue 因为不光是root的左右子树
            if (!p || !q || p->val != q->val) return false;

            stk.push(p->left);
            stk.push(q->right);
            stk.push(p->right);
            stk.push(q->left);
        }
        return true;
    }
};