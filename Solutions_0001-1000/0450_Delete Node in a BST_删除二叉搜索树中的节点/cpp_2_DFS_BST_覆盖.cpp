
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root, key);
        return root;        
    }

    void del(TreeNode* &root, int key) {
        if (!root)  return;
        if (key == root->val) {
            // 1) 是叶节点
            if (!root->left && !root->right)  root = nullptr;
            // 2) 只有一个子节点 (只有右儿子 or 只有左儿子)
            else if (!root->left)  root = root->right;
            else if (!root->right)  root = root->left;
            // 3) 有 2 个子节点，左右儿子都存在
            else {
                auto p = root->right;
                while (p->left)  p = p->left;  // 找后继，一定没有左儿子
                root->val = p->val; // 将后继的值覆盖到当前节点上
                del(root->right, p->val);
            }
        }
        else if (key < root->val)  del(root->left, key);
        else del(root->right, key);
    }
};

// -----------2023年6月30日自己写的------------

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
    void dfs(TreeNode* &root, int &key) {
        if (!root) return;
        if (root->val == key) {
            if (!root->left && !root->right)
                root = nullptr;
            else if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else {
                auto p = root->right;
                while (p->left)
                    p = p->left;
                root->val = p->val;
                dfs(root->right, p->val);
            }
        }
        else if (root->val > key)
            dfs(root->left, key);
        else
            dfs(root->right, key);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        dfs(root, key);
        return root;
    }
};