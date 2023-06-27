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
    int maxc, cnt, last;
    vector<int> res;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);

        if (!cnt || last == root->val) {
            cnt ++;
            last = root->val;
        } else { //新开一段
            last = root->val;
            cnt = 1;
        }
        if (cnt > maxc) {
            res = {last};
            maxc = cnt;
        } else if (cnt == maxc){
            res.push_back(last);
        }
        
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};