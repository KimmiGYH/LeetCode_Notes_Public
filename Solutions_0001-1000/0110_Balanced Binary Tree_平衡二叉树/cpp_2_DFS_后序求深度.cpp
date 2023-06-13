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
    int res;

    int getHeight(TreeNode* node) {
        if (!node)
            return 0;
        
        int lh = getHeight(node->left); // 左
        if (lh == -1) return -1;
        int rh = getHeight(node->right);// 右
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1)      // 中
            res = -1;
        else
            res = max(lh, rh) + 1; // 以当前节点为根节点的树的最大高度
        
        return res;
    }

    bool isBalanced(TreeNode* root) {
        if (getHeight(root) == -1)
            return false;
        return true;
    }
};