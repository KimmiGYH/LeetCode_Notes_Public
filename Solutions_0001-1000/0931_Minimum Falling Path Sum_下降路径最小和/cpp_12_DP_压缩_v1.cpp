#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int N = A.size();
        vector<int> f(N + 2, INT_MAX);
        vector<int> cur(N + 2, INT_MAX);
        int minSum = INT_MAX;
        
        for(int j = 1; j < N + 1; ++j) 
        	cur[j] = A[0][j - 1]; //初始化第一行，注意加了两列后下标的错位
        
        for(int i = 1; i < N; ++i) {
            for(int j = 1; j < N + 1; ++j)
        		f[j] = A[i][j - 1] + min(min(cur[j - 1], cur[j]), cur[j + 1]);
            cur = f;
        }
        
        return *min_element(cur.begin(), cur.end());
        /*等价于*/
        
        // for (int j = 1; j < N + 1; ++j)
        //     minSum = min(minSum, cur[j]);
        
        // return minSum;
    }
};
