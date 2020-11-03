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
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) 
        {
            int len = q.size();
            auto t = q.front();
            for (int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                // 先 right 后 left
                if (t->right) q.push(t->right);
                if (t->left) q.push(t->left);
            }
            res.push_back(t->val);
        }
        return res;
    }
};