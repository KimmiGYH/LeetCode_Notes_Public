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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root)  q.push(root);

        while (q.size()) {
            vector<int> level; //把一层节点记到vector里
            int len = q.size();

            while (len--) {
                auto t = q.front();
                q.pop();
                level.push_back(t->val);
                if (t->left)  q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

// ------------2023年6月5日--------------

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            vector<int> ans;
            int sz = q.size();
            while (sz --) {
                auto t = q.front();
                q.pop();
                ans.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(ans);
        }
        return res;
    }
};