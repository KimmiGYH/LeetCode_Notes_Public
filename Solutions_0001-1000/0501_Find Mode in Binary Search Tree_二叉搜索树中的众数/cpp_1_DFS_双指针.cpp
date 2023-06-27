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
    TreeNode* pre = nullptr;
    vector<int> res;
    int maxc, cnt;

    void dfs (TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (!pre || pre->val == root->val) {
            cnt ++;
            pre = root;
        } else {
            cnt = 1;
            pre = root;
        }
        if (cnt == maxc)
            res.push_back(pre->val);
        else if (cnt > maxc) {
            maxc = cnt;
            res.clear();
            res.push_back(pre->val);
        }

        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};