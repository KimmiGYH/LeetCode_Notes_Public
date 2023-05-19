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
        cur += root->val + 'a';
        if (!root->left && !root->right) {
            string temp = cur;            
            reverse(temp.begin(), temp.end());
            if (res == "" || temp < res)
                res = temp;
        }
        dfs(root->left, cur, res);
        dfs(root->right, cur, res);
        cur.pop_back();
    }
};