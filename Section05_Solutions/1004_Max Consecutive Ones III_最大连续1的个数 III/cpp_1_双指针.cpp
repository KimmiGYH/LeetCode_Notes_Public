class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for (int i = 0, j = 0, cnt = 0; j < n; j++) {
            if (!nums[j]) cnt++; //cnt表示当前区间当中0的个数
            while (cnt > k) {
                if (!nums[i]) cnt--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};