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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if (!root)
            return res;
        stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            if (root->left)
                stk.push(root->left);  //调换顺序
            if (root->right)
                stk.push(root->right);
        }
        reverse(res.begin(), res.end()); //翻转数组
        return res;
    }
};