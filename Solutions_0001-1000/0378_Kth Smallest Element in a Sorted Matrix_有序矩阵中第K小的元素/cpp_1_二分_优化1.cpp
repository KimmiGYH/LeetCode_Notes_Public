#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while (l < r) {
            int mid = (long long)l + r >> 1;
            int j = matrix[0].size() - 1, cnt = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                while (j >= 0 && matrix[i][j] > mid) j--;
                cnt += j + 1;
            }
            if (cnt >= k) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};
