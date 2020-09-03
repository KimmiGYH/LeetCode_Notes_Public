// 1. Two Sum / Solution 4
// 二分查找 / C++
// Time complexity: O(nlog(n))
// Space complexity: _______

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;

    static int my_binary_search(vector<PII> &vec, int h, int x) { // 起始坐标h，待查找值x
        int head = h, tail = vec.size() - 1, mid;
        while (head <= tail) {
            mid = (head + tail) >> 1;
            if (vec[mid].first == x) return vec[mid].second;
            if (vec[mid].first < x) head = mid + 1;
            else tail = mid - 1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<PII> vec;
        for (int i = 0; i != nums.size(); ++i) {
            vec.push_back(PII(nums[i], i));
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i != vec.size(); ++i) {
            int index1 = vec[i].second;
            int val = target - vec[i].first;
            int index2 = my_binary_search(vec, i+1, val);
            if (index2 == -1) continue;
            if (index1 > index2) swap(index1, index2);
            ret.push_back(index1);
            ret.push_back(index2);
            break;
        }
        return ret;
    }
};
