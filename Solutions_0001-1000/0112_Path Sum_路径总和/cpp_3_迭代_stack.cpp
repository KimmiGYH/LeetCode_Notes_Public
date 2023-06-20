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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, root->val));
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            if (!t.first->left && !t.first->right && t.second == targetSum)
                return true;
            if (t.first->right)
                stk.push(make_pair(t.first->right, t.second + t.first->right->val));
            if (t.first->left)
                stk.push(make_pair(t.first->left, t.second + t.first->left->val));
        }
        return false;
    }
};