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
// 未完待续
    void convert(TreeNode* node, vector<int>& arr) {
        if (!node) {
            arr.push_back(INT_MAX);
            return;
        }
        arr.push_back(node->val);
        convert(node->left, arr);
        convert(node->right, arr);
    }

    vector<int> preprocess(vector<int>& P) {
        int n = P.size();
        P = P.insert(P.begin(), 0);
        vector<int> nxt(n + 1, 0);
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && P[i] != P[j + 1])
                j = nxt[j];
            if (P[i] == P[j + 1])
                j ++;
            nxt[i] = j;
        }
        return nxt;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> S, T;
        convert(root, S);
        convert(subRoot, T);
        vector<int> suff = preprocess(subRoot);
        
        vector<int> nxt(n + 1, 0);


    }
};