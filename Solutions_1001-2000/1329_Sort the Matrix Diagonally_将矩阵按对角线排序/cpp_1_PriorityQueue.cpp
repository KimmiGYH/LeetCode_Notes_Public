#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // 在同一条对角线上的元素有相同的 i-j 值
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hash; // min priority queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hash[i - j].push(mat[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = hash[i - j].top(); hash[i - j].pop();
            }
        }
        return mat;
    }
};