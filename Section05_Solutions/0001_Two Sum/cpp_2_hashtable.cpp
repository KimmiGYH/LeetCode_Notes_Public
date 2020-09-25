// 1. Two Sum / Solution 2
// Hashtable / C++
// Time complexity: O(n)
// Space complexity: O(n)


// 写法1：

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i != nums.size(); ++i) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i != nums.size(); ++i) {
            int val = target - nums[i];
            // if (indices.count(val)) {
            if (indices.count(val) && indices[val] != i) {
                return {i, indices[val]};
            }
        }

        return {};
    }
}; 

/*
indices.count() 的 .count() 返回布尔值，测试整数 val 是否在 indices这个哈希表中。

第20行条件如果写成 if (indices.count(val)) 会出现以下测试用例无法通过的情况：[3,2,4] 6
期望的下标结果是[1,2]，但得到的实际结果是[0,0]，也就是 3+3=6 的情况；
由于题干中要求数据只能用一次，所以我们要排除两个下标相同的情况。
*/

// 写法2：

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> indices;
        for (int i = 0; i != nums.size(); ++i) {
            int val = target - nums[i];
            if (indices.find(val) == indices.end()) { // 如果没找到
                indices[nums[i]] = i;                
            } else { // 找到了
                ret.push_back(indices[val]);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
}; 
