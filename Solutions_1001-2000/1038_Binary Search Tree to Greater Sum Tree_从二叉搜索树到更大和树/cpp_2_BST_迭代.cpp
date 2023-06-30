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
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return nullptr;
        stack<TreeNode*> stk;
        int sum = 0;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->right;
            } else {
                cur = stk.top();
                stk.pop();
                int x = cur->val;
                cur->val += sum;
                sum += x;
                cur = cur->left;
            }
        }
        return root;
    }
};