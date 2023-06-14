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
    vector<string> res;
    vector<int> path;

    void dfs(TreeNode* root) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            string str = to_string(path[0]);
            for (int i = 1; i < path.size(); i++)
                str += "->" + to_string(path[i]);
            res.push_back(str);
            return;
        }

        if (root->left) {
            dfs(root->left);
            path.pop_back();
        }
        if (root->right) {
            dfs(root->right);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return res;
        dfs(root);
        return res;
    }
};