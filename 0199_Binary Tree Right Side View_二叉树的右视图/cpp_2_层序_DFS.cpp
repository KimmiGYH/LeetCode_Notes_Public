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
    void DFS(TreeNode* root, int depth, vector<int>& res) {
        if (!root)  return;
        
        while(res.size() <= depth)
            res.push_back(root->val); // pre-order
        DFS(root->right, depth + 1, res);
        DFS(root->left, depth + 1, res);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        DFS(root, 0, res);
        return res;
    }
};