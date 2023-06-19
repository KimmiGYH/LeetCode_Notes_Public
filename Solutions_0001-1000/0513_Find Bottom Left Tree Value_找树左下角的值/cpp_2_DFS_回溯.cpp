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
    int maxDepth = INT_MIN;
    int res = 0;

    void dfs(TreeNode* root, int depth) {
        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = root->val;
            }
        }
        if (root->left) {
            depth ++;
            dfs(root->left, depth);
            depth --;
        }
        if (root->right) {
            depth ++;
            dfs(root->right, depth);
            depth --;
        }
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return res;    
    }
};