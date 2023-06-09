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

// 后序遍历
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)  return nullptr;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

// ---------------2023年6月9日-------------------
// 前序遍历
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};