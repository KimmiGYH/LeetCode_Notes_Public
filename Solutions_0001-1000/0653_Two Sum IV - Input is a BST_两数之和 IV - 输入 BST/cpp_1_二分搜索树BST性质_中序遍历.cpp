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
    vector<int> vec;
    
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        vec.push_back(root->val);
        dfs(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int n = vec.size();
        int l = 0, r = n - 1;
        while (l != r) {
            int sum = vec[l] + vec[r];
            if (sum == k) return true;
            else if (sum > k) r--;
            else if (sum < k) l++;
        }
        return false;
    }
};