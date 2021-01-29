#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:    
    string smallestFromLeaf(TreeNode* root) {
        string res = "";
        dfs(root, "", res);
        return res;        
    }
    
    void dfs(TreeNode* root, string cur, string& res) {
        if (!root) return;
        cur += (char)(root->val + 'a');
        if (!root->left && !root->right) {
            reverse(cur.begin(), cur.end());
            if (res == "" || cur < res)
                res = cur;
            reverse(cur.begin(), cur.end());
        }
        dfs(root->left, cur, res);
        dfs(root->right, cur, res);
        cur.pop_back();
    }
};