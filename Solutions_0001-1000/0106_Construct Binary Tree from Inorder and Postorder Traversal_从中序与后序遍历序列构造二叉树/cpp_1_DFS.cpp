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
    
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int posL, int posR) {
        if (posL > posR) return NULL;
        TreeNode* root = new TreeNode(postorder[posR]);
        int k = hash[root->val];
        root->left = dfs(inorder, postorder, inL, k - 1, posL, posL + k - 1 - inL);
        root->right = dfs(inorder, postorder, k + 1, inR, posL + k - 1 - inL + 1, posR - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;
        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};

// -------------2023年6月25日---------------

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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if (il > ir) return NULL;
        TreeNode* root = new TreeNode(postorder[pr]);
        int k = hash[root->val];
        root->left = build(inorder, postorder, il, k-1, pl, pl + k-1 - il);
        root->right = build(inorder, postorder, k+1, ir, pl + k-1 - il + 1, pr - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};