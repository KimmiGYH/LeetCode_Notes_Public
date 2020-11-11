#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
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
    unordered_map<int, int> cnt;
    int res = 0;

    int pathSum(TreeNode* root, int sum) {
        cnt[0]++;
        dfs(root, sum, 0);
        return res;
    }

    void dfs(TreeNode* root, int sum, int cur) {
        if (!root)  return;
        cur += root->val;
        res += cnt[cur - sum];
        cnt[cur]++;
        dfs(root->left, sum, cur), dfs(root->right, sum, cur);
        cnt[cur]--;
    }

    TreeNode* dfs_deser(string data, int u) {
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

int main() {
    // string data = "10,5,-3,3,2,#,11,3,-2,#,1";
    string data = "10,5,3,3,#,#,#";
    int u = 0;
    int sum = 8;

    TreeNode* root = Solution().dfs_deser(data, u);

    int path_sum = Solution().pathSum(root, sum);

    cout << path_sum << endl;    
}