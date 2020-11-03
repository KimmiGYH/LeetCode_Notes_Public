#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root)  q.push(root);

        while (q.size()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                if (t->left)  q.push(t->left);
                if (t->right) q.push(t->right);
                if (i == len - 1)  res.push_back(t->val); // 把每层最后一个元素记下来
            }
        }
        return res;
    }
};