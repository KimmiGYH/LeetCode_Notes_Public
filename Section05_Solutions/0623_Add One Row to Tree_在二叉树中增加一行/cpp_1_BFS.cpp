#include <iostream>
#include <queue>

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // 题目要求，特判 d == 1 时
        if (d == 1) {
            auto cur = new TreeNode(v);
            cur->left = root;
            return cur;
        }
        bfs(root, v, d);
        return root;
    }
    
    void bfs(TreeNode* root, int& v, int& d) {
        queue<TreeNode*> q;
        q.push(root);
        // 根据题意 d 是从 1 ~ d-1，所以循环从 [0 ~ d-2) 次
        for (int i = 0; i< d - 2; i++) {
            // 把当前这一层循环完
            int len = q.size();
            while (len--) {
                auto t = q.front(); q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        
        // 至此，队列q里就是要加的层的上一层的所有结点
        while (q.size()) {
            auto t = q.front(); q.pop();
            auto l = new TreeNode(v), r = new TreeNode(v);
            l->left = t->left, r->right = t->right;
            t->left = l, t->right = r;
        }
    }
};