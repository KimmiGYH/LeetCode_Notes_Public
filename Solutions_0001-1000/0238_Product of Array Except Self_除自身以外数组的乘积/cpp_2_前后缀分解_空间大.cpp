#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), res(n, 1);
        for (int i = 0; i < n; i++) {
            if (i == 0) prefix[i] = nums[i];
            else prefix[i] = prefix[i - 1] * nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) suffix[i] = nums[i];
            else suffix[i] = suffix[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            int t = 1;
            if (i - 1 >= 0) t*= prefix[i - 1];
            if (i + 1 <= n) t *= suffix[i + 1];
            res[i] = t;
        }
        return res;        
    }
};