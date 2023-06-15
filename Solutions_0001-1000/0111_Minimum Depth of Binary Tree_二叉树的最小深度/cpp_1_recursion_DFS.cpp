#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)  return 0; // 如果当前节点为空
        if (!root->left && !root->right)  return 1; // 如果当前节点是叶节点(没有子节点)
        if (root->left && root->right) // 如果左右子树都不空
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left) // 如果左子树不空(但右子树空)返回左子树，否则返回右子树
            return minDepth(root->left) + 1;
        return minDepth(root->right) + 1;        
    }
};

// ------------------无注释版-----------------

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right)
            return 1;
        if (root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left)
            return minDepth(root->left) + 1;
        return minDepth(root->right) + 1;
    }
};

// ----------------2023年6月15日----------------

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left)
            return minDepth(root->left) + 1;
        if (root->right)
            return minDepth(root->right) + 1;
        return 0;
    }
};