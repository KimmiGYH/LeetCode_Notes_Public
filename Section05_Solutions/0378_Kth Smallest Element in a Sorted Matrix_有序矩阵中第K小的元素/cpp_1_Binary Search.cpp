#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = INT_MIN, r = INT_MAX;
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
