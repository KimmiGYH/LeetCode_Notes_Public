#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            // 取值域的中点
            int mid = l + r >> 1; // [l, mid], [mid+1, r]
            int s = 0;
            // 每次统计左半边数的个数
            for (auto x : nums)
                s += x >= l && x <= mid;
            if (s > mid - l + 1) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};