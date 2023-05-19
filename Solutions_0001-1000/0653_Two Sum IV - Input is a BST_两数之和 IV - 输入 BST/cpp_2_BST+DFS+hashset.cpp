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
    int k;
    unordered_set<int> hash;
    
    bool dfs(TreeNode* x) {
        if (x == nullptr)
            return false;
        if (hash.count(k - x->val)) return true;
        hash.insert(x->val);
        return dfs(x->left) || dfs(x->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        this->k = k;
        return dfs(root);
    }
};