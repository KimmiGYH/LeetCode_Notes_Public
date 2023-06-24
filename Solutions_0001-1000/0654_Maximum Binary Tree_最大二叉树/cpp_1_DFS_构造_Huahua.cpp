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
    // Time: O(nlogn) ~ O(n^2)
    // Space: O(nlogn) ~ O(n^2)
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        // O(n)
        auto it = std::max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*it);
        vector<int> left(nums.begin(), it);
        vector<int> right(it + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};