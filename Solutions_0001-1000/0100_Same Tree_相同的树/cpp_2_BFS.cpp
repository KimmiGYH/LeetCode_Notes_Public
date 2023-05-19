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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> Q;
        Q.push(p); Q.push(q);
        while (Q.size()) {
            p = Q.front(); Q.pop();
            q = Q.front(); Q.pop();
            if (!p && !q)  continue;
            if (!p || !q || p->val != q->val) return false;

            Q.push(p->left); Q.push(q->left);
            Q.push(p->right); Q.push(q->right);
        }
        return true;
    }
};