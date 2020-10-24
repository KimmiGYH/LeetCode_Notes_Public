#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> S;
        for (auto x : nums1)  S.insert(x);
        vector<int> res;
        for (auto x : nums2)
            if (S.count(x)) {
                res.push_back(x);
                S.erase(S.find(x)); // S.erase(x)是删掉所有的 x
            }
        return res;
    }
};