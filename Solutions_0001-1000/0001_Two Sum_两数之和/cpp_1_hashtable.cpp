#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int x = target - nums[i];
            if (hash.count(x)) return {hash[x], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};

//------错误解法❌-------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i; //这一步如果元素相同，第二个元素的下标会覆盖掉第一个元素下标
            int val = target - nums[i];
            if (hash.count(val) && hash[val] != i) {//导致 hash[val] != i 无法满足
                res.push_back(hash[val]);
                res.push_back(i);
                return res;
            }
        }
        return {};
    }
};