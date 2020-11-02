// LeetCode 144
#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        
        while(root || stk.size()) {
            while (root) {
                res.push_back(root->val); // 先根遍历，将根加到栈里
                stk.push(root);
                root = root->left;
            }

            root = stk.top()->right; // 左子树遍历完后直接遍历右子树 不需要遍历根节点
            stk.pop();
        }
        return res;
    }
};