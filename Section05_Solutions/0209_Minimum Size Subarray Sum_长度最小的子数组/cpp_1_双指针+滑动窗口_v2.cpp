#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int sum = 0;
        int res = INT_MAX;
        int j = -1; // j - left pointer; (j, i]
        for (int i = 0; i < nums.size(); i++) // i - right pointer
        {
            sum += nums[i];
            while (sum >= s)
            {
                res = min(res, i - j);
                j++;
                sum -= nums[j];
            }
        }
        return res == INT_MAX ? 0 : res;        
    }
};