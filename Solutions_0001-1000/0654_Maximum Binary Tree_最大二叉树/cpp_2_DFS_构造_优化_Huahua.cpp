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
        return makeMBT(nums, 0, nums.size());
    }
private:
    TreeNode* makeMBT(const vector<int>& nums, int left, int right) {
        if (left >= right)
            return nullptr;
        auto iter = std::max_element(nums.begin() + left, nums.begin() + right);
        TreeNode* root = new TreeNode(*iter);
        int index = iter - nums.begin();
        root->left = makeMBT(nums, left, index);
        root->right = makeMBT(nums, index + 1, right);
        return root;
    }
};