#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        int level = 0;
        while (!q.empty()) {            
            int len = q.size();
            int value = (level == 0) ? INT_MIN : INT_MAX;
            while (len--) {
                auto cur = q.front(); q.pop();
                if ((level == 0) && (cur->val % 2 == 0 || cur->val <= value) ||
                    (level == 1) && (cur->val % 2 == 1 || cur->val >= value))
                    return false;
                value = cur->val;
                if (cur->left)  q.push(cur->left);
                if (cur->right)  q.push(cur->right);
            }
            level ^= 1;
        }
        return true;
    }
};