#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxWin = -1, sum = 0, curSum = 0, l = 0, r = 0;
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        while (r < n) {
            curSum += nums[r++];
            while (curSum > target && l < n)
                curSum -= nums[l++];
            if (curSum == target)
                maxWin = max(maxWin, r - l);
        }
        // return maxWin == -1 ? -1 : n - maxWin;
        if (maxWin == -1) return -1;
        return n - maxWin;
    }
};

/*
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxWin = -1, sum = 0, curSum = 0, l = 0, r = 0;
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        while (r < n) {
            curSum += nums[r++];
            cout << "r: " << r << ' ';
            while (curSum > target && l < n)
                curSum -= nums[l++];
                cout << "l: " << l << ' ';
            if (curSum == target)
                maxWin = max(maxWin, r - l);
            cout << endl;
        }
        if (maxWin == -1) return -1;
        return n - maxWin;
    }
};
*/