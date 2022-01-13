class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //tot 为1的个数，cnt 为0的个数，
        int n = nums.size(), tot = 0, cnt = 0, res = INT_MAX;
        for (int& x : nums)
            tot += x == 1;
        if (tot == n) return 0;
        for (int j = 0; j < tot; j++)
            if (!nums[j]) cnt++;
        for (int i = 0, j = tot; j < n + tot; j++) {
            if (!nums[j % n]) cnt++;
            if (j - i + 1 > tot)
                if (!nums[i++ % n]) cnt--;
            res = min(res, cnt);
        }
        return res;
    }
};
