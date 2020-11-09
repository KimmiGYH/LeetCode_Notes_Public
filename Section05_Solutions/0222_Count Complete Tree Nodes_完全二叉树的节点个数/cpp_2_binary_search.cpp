#include <vector>
using namespace std;

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
    int countNodes(TreeNode* root) {
        int h = 0;
        TreeNode* node = root;
        while (node != nullptr) {
            h++;
            node = node->left;
        }
        int low = pow(2, h-1);
        int hi = pow(2, h) - 1;

        while (low < hi) {
            int mid = low + (hi - low + 1) / 2; // 右移
            if (hasK(root, mid))
                low = mid;
            else
                hi = mid - 1;
        }
        return low;
    }

    bool hasK(TreeNode* root, int K) {
        vector<int> path;
        while (K > 0) {
            path.push_back(K);
            K /= 2;
        }
        for (int i = path.size() - 1; i >= 0; i--) {
            if (root == nullptr)  return false;
            if (i == 0)  return true;

            if (path[i - 1] == path[i] * 2)
                root = root->left;
            else
                root = root->right;
        }
        return false;
    }
};