#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> hash;
        int res = 0;
        for (int i = 0, j = 0, sum = 0; i < nums.size(); i++) {
            int x = nums[i];
            sum += x;
            hash[x]++;
            while (hash[x] > 1) {
                sum -= nums[j];
                hash[nums[j++]]--;
            }
            res = max(res, sum);
        }
        return res;
    }
};