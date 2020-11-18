// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
q       p

0		0		表示 p、q 都没有

0		1		表示有 p 无 q

1		0		表示有 q 无 p

1		1		表示 p、q 都有    */

class Solution {
public:
    TreeNode* ans = nullptr;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;        
    }

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)  return 0;
        int state = dfs(root->left, p, q);
        if (root == p)  state |= 1;
        else if (root == q)  state |= 2;
        state |= dfs(root->right, p, q);
        if (state == 3 && !ans)  ans = root;
        return state;
    }
};