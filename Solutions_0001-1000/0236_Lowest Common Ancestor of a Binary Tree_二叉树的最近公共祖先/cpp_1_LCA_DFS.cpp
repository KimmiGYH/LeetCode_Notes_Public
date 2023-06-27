// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)  return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q); //左
        TreeNode* right = lowestCommonAncestor(root->right, p, q); //右
        //中
        if (!left && !right)  return nullptr; // 1. left 和 right 同时为空
        if (!left)  return right; // 3. left 为空，right 不为空
        if (!right)  return left; // 4. right 为空，left 不为空
        return root; // 2. left 和 right 同时不为空 if (left != NULL && right != NULL)
    }
};