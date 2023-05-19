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

    bool dfs(TreeNode* root) { // 为了提前返回，用 bool 类型
        if (!root)  return false;
        if (dfs(root->left))  return true; // 如果左边搜到了答案 则可以直接返回
        if (--cnt == 0) { // 表示当前遍历的数恰好是第 k 小的数
            ans = root->val;
            return true;
        }
        return dfs(root->right);
    }
};