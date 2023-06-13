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
    int result;

    void getDepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result; //中
        if (!node->left && !node->right)
            return;
        if (node->left) { // 左
            depth ++;     // 深度+1
            getDepth(node->left, depth);
            depth --;     // 回溯，深度-1
        }
        if (node->right) {// 右
            depth ++;     // 深度+1
            getDepth(node->right, depth);
            depth --;     // 回溯，深度-1
        }
        return;
    }

    int maxDepth(TreeNode* root) {
        result = 0;
        if (!root) return result;
        getDepth(root, 1);
        return result;
    }
};