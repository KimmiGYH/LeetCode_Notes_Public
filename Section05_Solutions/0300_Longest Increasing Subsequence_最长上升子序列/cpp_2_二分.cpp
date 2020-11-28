#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        for (auto x : nums) {
            if (vec.empty() || x > vec.back())  vec.push_back(x);
            else if (x <= vec[0])  vec[0] = x;
            else {
                int l = 0, r = vec.size() - 1;
                while (l < r) {
                    int mid = l + r + 1>> 1;
                    if (vec[mid] < x)  l = mid;
                    else r = mid - 1;
                }
                vec[r + 1] = x;
            }
        }
        return vec.size();
    }
};