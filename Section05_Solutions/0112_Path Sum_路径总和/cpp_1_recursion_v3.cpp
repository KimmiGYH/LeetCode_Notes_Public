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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!root->left && !root->right) // 根到“叶子”节点
            return !sum; // 当只有根节点时，如果满足，那么 sum -= root->val 后 sum 为 0，满足的话 !sum 为 true
        
        return hasPathSum(root->left, sum ) || hasPathSum(root->right, sum);
    }
};