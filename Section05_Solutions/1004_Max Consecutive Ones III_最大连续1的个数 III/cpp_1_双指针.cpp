class Solution {
public:
    //找个最大区间最多包含k个0
    int longestOnes(vector<int>& nums, int k) {
        int res = INT_MIN;
        for (int i = 0, j = 0, cnt = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) cnt ++;//cnt表示当前区间当中0的个数
            while (k < cnt) {
                if (nums[j] == 0) cnt--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};