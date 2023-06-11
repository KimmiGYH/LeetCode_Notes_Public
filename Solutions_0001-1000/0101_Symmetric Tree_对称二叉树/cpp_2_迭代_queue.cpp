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
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            auto p = que.front(); que.pop();
            auto q = que.front(); que.pop();
            if (!p && !q) continue; // continue 因为不光是root的左右子树
            if (!p || !q || p->val != q->val) return false;

            que.push(p->left);
            que.push(q->right);
            que.push(p->right);
            que.push(q->left);
        }
        return true;
    }
};