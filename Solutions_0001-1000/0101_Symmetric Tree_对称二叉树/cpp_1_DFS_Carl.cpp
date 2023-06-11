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
    bool compare(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p && q) return false;
        if (p && !q) return false;
        if (p->val != q->val) return false;

        bool outside = compare(p->left, q->right);
        bool inside = compare(p->right, q->left);
        bool isSame = outside && inside;
        return isSame;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }
};