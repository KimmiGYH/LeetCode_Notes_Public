#include <iostream>
#include <unordered_map>
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
    unordered_map<int, int> hash;
    int pseudoPalindromicPaths (TreeNode* root) {
        hash[root->val]++;
        if (!root->left && !root->right) {
            int cnt = 0;
            for (auto item : hash)
                if (item.second % 2)
                    cnt++;
            hash[root->val]--;
            return cnt <= 1; // 判断伪回文串: 最多只有一个出现次数是奇数的字符
        }

        int res = 0;
        if (root->left) res += pseudoPalindromicPaths(root->left);
        if (root->right) res += pseudoPalindromicPaths(root->right);

        hash[root->val]--;
        return res;
    }
};