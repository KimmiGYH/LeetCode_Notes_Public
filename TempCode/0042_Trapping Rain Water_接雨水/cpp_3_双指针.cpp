#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), i = 0, j = n - 1, res = 0;
        if (n == 0) return 0;
        int left_max = 0, right_max = 0;
        while (i < j)
        {
            if (height[i] < height[j]) {
                left_max = max(left_max, height[i]);
                res += left_max - height[i];
                i++;
            } else {
                right_max = max(right_max, height[j]);
                res += right_max - height[j];
                j--;
            }
        }
        return res;
    }
};