class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), tot = 0, cnt = 0, res = 0;
        for (int& x : nums)
            tot += x == 1;
        if (tot == n) return 0;
        for (int i = 0, j = 0; j < n + tot; j++) {
            if (nums[j % n]) cnt++;
            if (j - i + 1 > tot) {
                if (nums[i % n]) cnt--;
                i++;
            }
            res = max(res, cnt);
        }
        return tot - res;
    }
};

// ----------------------------------------------------

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), tot = 0, cnt = 0, res = 0;
        for (int& x : nums) tot += x;
        for (int i = 0, j = 0; j < n + tot; j++) {
            if (nums[j % n]) cnt++;
            if (j - i + 1 > tot)
                if (nums[i++ % n]) cnt--;
            res = max(res, cnt);
        }
        return tot - res;
    }
};
