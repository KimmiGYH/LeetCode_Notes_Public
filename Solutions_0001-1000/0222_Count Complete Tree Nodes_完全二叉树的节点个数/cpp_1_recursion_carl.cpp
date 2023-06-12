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
    int getNodesNum(TreeNode* root) {
        if (!root) return 0;
        int leftNum = getNodesNum(root->left);
        int rightNum = getNodesNum(root->right);
        int treeNum = leftNum + rightNum + 1;
        return treeNum;
    }

    int countNodes(TreeNode* root) {
        return getNodesNum(root);
    }
};

// -----------代码精简之后C++代码----------

// 版本二
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};