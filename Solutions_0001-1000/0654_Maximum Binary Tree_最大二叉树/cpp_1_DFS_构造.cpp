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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1){
            node->val = nums[0];
            return node;
        }
        // 找到数组中最大的值和对应的下标
        int maxVal = 0;
        int maxValIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxValIndex = i;
            }
        }
        node->val = maxVal;
        // 最大值所在的下标左区间 构造左子树
        if (maxValIndex > 0) {
            vector<int> newVec(nums.begin(), nums.begin() + maxValIndex); //左闭右开
            node->left = constructMaximumBinaryTree(newVec);
        }
        // 最大值所在的下标右区间 构造右子树
        if (maxValIndex < nums.size() - 1) {
            vector<int> newVec(nums.begin() + maxValIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};