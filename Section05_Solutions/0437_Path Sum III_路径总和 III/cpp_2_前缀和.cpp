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
    int pathSum(TreeNode* root, int sum) {
      if(!root) return 0;
      // 可能存在以头结点为路径起始，所以头节点之前也要计数一次
      hash[0] = 1; // 等价于hash = {{0, 1}};
      dfs(root, sum, 0);
      return ans;
    }
private:
    int ans = 0;
    unordered_map<int,int> hash;
    void dfs(TreeNode* root, int& sum, int routeSum){
        if(!root) return;
        // 路径和累加
        routeSum += root->val;

        // 将以当前节点为尾节点的等于sum（符合条件）的路径条数加到结果上
        // 因为是以当前节点为路径尾部，所以计数不会重复
        ans += hash[routeSum - sum];
        
        // 将当前的前缀和记录下来
        hash[routeSum]++;
        dfs(root->left, sum, routeSum);
        dfs(root->right, sum, routeSum);
        hash[routeSum]--;
    }
};