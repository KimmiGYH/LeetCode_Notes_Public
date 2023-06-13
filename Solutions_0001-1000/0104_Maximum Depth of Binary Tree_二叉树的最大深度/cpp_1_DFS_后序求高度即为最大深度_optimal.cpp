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
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int lh = getHeight(root->left);  //左
        int rh = getHeight(root->right); //右
        int height = 1 + max(lh, rh);    //中
        return height;
    }

    int maxDepth(TreeNode* root) {
        return getHeight(root);
    }
};

// --------------精简版代码----------------

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};