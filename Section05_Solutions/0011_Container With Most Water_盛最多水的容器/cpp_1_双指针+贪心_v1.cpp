#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            // 舍弃短板
            if (height[i] < height[j]) ++i;
            else --j;
        }
        return res;
    }
};