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
    int cnt, ans;

    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        dfs(root); // inorder traversal
        return ans;
    }

    void dfs(TreeNode* root) {
        if (root->left)  dfs(root->left);
        if (--cnt == 0) { // 表示当前遍历的数恰好是第 k 小的数
            ans = root->val;
            return;
        }
        if (root->right)  dfs(root->right);
    }
};