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
private:
    void DFS(TreeNode* root, int depth, vector<vector<int>>& ans) {
        if (!root)  return;
        // Works with pre/in/post order
        while(ans.size() <= depth) ans.push_back({});
        ans[depth].push_back(root->val); // pre-order
        DFS(root->left, depth + 1, ans);
        DFS(root->right, depth + 1, ans);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        DFS(root, 0 /*depth*/, ans);
        return ans;
    }
};