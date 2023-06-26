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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        queue<TreeNode*> q;
        q.push(root1);
        q.push(root2);
        while (!q.empty()) {
            auto t1 = q.front(); q.pop();
            auto t2 = q.front(); q.pop();
            t1->val += t2->val;

            // 如果两棵树左节点都不为空，加入队列
            if (t1->left && t2->left) {
                q.push(t1->left);
                q.push(t2->left);
            }
            // 如果两棵树右节点都不为空，加入队列
            if (t1->right && t2->right) {
                q.push(t1->right);
                q.push(t2->right);
            }

            // 当t1的左节点 为空 t2左节点不为空，就赋值过去
            if (!t1->left && t2->left)
                t1->left = t2->left;
            
            // 当t1的右节点 为空 t2右节点不为空，就赋值过去
            if (!t1->right && t2->right)
                t1->right = t2->right;
        }
        return root1;
    }
};