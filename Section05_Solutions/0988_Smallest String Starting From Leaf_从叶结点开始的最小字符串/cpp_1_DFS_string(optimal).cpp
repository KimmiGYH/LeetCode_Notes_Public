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
        string res = "|"; // ASCII码值大于z的符号都可
        dfs(root, "", res);
        return res;        
    }
    
    void dfs(TreeNode* root, string cur, string& res) {
        if (!root) return;
        cur = string(1, root->val + 'a') + cur; // 构造一个长度为1的字符串,内容为node->val+'a'
        if (!root->left && !root->right)
            res = min(res, cur);
        dfs(root->left, cur, res);
        dfs(root->right, cur, res);
    }
};