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
    unordered_map<int, int> hash;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if (preL > preR) return NULL;
        TreeNode* root = new TreeNode(preorder[preL]); // root的值为preorder[preL]的值，不是 preorder[0]
        //k为inorder里根节点的下标值
        int k = hash[root->val]; //k 的值为 hash[root->val]，不是 hash[preorder[0]]
        root->left = dfs(preorder, inorder, preL + 1, preL + 1 + k - 1 - inL, inL, k - 1);
        root->right = dfs(preorder, inorder, preL + 1 + k - 1 - inL + 1, preR, k + 1, inR);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};