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
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left >= right)
            return nullptr;
        int maxValIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > nums[maxValIndex])
                maxValIndex = i;
        }
        TreeNode* root = new TreeNode(nums[maxValIndex]);
         // 左闭右开：[left, maxValueIndex)
         root->left = dfs(nums, left, maxValIndex);
         // 左闭右开：[maxValueIndex + 1, right)
         root->right = dfs(nums, maxValIndex + 1, right);

         return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
};