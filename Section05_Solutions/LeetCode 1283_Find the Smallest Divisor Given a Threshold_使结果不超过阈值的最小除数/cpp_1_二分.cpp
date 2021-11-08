#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = l + r >> 1, total = 0;
            for (int n : nums)
                total += (n + mid - 1) / mid;
            if (total <= threshold) r = mid;
            else l = mid + 1;
        }
        return l;        
    }
};