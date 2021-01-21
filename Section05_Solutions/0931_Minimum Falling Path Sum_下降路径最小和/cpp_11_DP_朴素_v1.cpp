#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /* 动态规划，每次取上一行的正上方、左上方、右上方的3个值的最小的
       加了左右两个边界，方便代码统一处理  */
    int minFallingPathSum(vector<vector<int>>& A) {
        const int N = A.size();
        vector<vector<int>> f(N, vector<int>(N+2, INT_MAX));
        int minSum = INT_MAX;
        
        for(int j = 1; j < N + 1; ++j) 
        	f[0][j] = A[0][j - 1]; //初始化第一行，注意加了两列后下标的错位
        
        for(int i = 1; i < N; ++i)
        	for(int j = 1; j < N + 1; ++j)
        		f[i][j] = A[i][j - 1] + min(min(f[i - 1][j - 1], f[i - 1][j]), f[i - 1][j + 1]);
        
        for(int j = 1; j < N + 1; ++j)
        	minSum = min(minSum, f[N - 1][j]);
        
        return minSum;
    }
};
