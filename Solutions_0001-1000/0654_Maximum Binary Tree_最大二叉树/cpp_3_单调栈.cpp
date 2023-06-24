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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for (int x : nums) {
            TreeNode* node = new TreeNode(x);
            while (stk.size() && x > stk.top()->val) {
                node->left = stk.top();
                stk.pop();
            }
            if (stk.size())
                stk.top()->right = node;
            stk.push(node);
        }
        while (stk.size() > 1) // 清空单调栈，剩下的就是最大的结点
            stk.pop();
        return stk.top();
    }
};