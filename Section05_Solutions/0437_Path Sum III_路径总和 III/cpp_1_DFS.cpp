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
    // 在以 root 为根节点的二叉树中，寻找和为 sum 的路径，返回这样的路径个数
    // (不一定是从根开始 到叶子节点结束)
    int pathSum(TreeNode* root, int sum) {
        
        if (!root)  return 0;

        // 1. 考虑 root 节点的情况
        int res = dfs(root, sum); 

        // 2. 不考虑 root节点 的情况，在左右子树中寻找
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);

        return res;
    }

private:
    // 在以 node 为根节点的二叉树中，寻找包含 node 的路径，和为 num，返回这样的路径个数
    int dfs(TreeNode* node, int num) {

        if (!node)  return 0;

        int res = 0;
        if (node->val == num)
            res += 1;
        
        res += dfs(node->left, num - node->val);
        res += dfs(node->right, num - node->val);

        return res;
    }
};