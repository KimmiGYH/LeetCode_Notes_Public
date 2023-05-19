#include <iostream>
#include <queue>
#include <vector>
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
            vector<int> v;
            int len = q.size();
            while (len--) {
                auto t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->left)  q.push(t->left);
                if (t->right)  q.push(t->right);
            }

            for (int i = 0; i < v.size(); i++) {
                if (level % 2 == 0) {
                    if (v[i] % 2 == 0)
                        return false;
                    if (i < v.size() - 1 && v[i] >= v[i+1])
                        return false;
                } else {
                    if (v[i] % 2 == 1)
                        return false;
                    if (i < v.size() - 1 && v[i] <= v[i+1])
                        return false;
                }
            }
            level++;
        }
        return true;
    }
};