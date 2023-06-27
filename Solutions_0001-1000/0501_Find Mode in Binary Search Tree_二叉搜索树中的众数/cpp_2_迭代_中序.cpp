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
    stack<TreeNode*> stk;
    vector<int> res;
    int maxc, cnt, last;

    vector<int> findMode(TreeNode* root) {
        if (!root) return res;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if (!cnt || last == root->val) {
                    cnt ++;
                    last = root->val;
                } else {
                    cnt = 1;
                    last = root->val;
                }
                if (cnt > maxc) {
                    maxc = cnt;
                    res.clear();
                    res.push_back(root->val);
                } else if (cnt == maxc) {
                    res.push_back(root->val);
                }
                
                root = root->right;
            }
        }
        return res;
    }
};