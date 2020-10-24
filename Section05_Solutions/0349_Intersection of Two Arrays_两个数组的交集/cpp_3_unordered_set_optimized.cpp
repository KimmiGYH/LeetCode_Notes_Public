#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S;
        for (auto x : nums1)  S.insert(x);
        vector<int> res;
        for (auto x : nums2)
            if (S.count(x)) { // 如果x在第一个数组中出现过的话
                res.push_back(x);
                S.erase(x);
            }
        return res;
    }
};