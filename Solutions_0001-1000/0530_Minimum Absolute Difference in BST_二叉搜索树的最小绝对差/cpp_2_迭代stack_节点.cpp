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
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode* pre = nullptr;
        stack<TreeNode*> stk;

        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;      // 左
            } else {
                root = stk.top();
                stk.pop();
                if (pre != nullptr)     // 中
                    diff = min(diff, root->val - pre->val);
                pre = root;

                root = root->right;     // 右
            }
        }
        return diff;
    }
};