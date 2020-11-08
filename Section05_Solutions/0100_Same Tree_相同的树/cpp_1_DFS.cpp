
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)  return true; // 两棵都是空树
        if (!p || !q || p->val != q->val)  return false; // 一棵空一棵非空，或虽都非空但值不同
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};