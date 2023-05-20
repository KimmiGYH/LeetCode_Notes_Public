#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto x : nums2)
            if (s1.count(x)) { // 如果x在第一个数组中出现过的话
                res.push_back(x);
                s1.erase(x);
            }
        return res;
    }
};