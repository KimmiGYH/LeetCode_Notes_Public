#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string path;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs_ser(root);
        return path;
    }

    void dfs_ser(TreeNode* root) {
        if (!root)  path += "#,";
        else {
            path += to_string(root->val) + ',';
            dfs_ser(root->left);
            dfs_ser(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_deser(data, u);
    }

    TreeNode* dfs_deser(string& data, int& u) {
        if (data[u] == '#') {
            u += 2; // 跳过 '#' 和 ','
            return nullptr;
        } else {
            int k = u;
            while (data[u] != ',')  u++;
            auto root = new TreeNode(stoi(data.substr(k, u-k)));
            u++; // 跳过紧跟着的 ','
            root->left = dfs_deser(data, u);
            root->right = dfs_deser(data, u);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));