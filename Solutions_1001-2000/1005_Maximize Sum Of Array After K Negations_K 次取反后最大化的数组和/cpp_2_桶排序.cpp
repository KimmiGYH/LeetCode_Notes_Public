class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt; //数，次数
        int res = 0, minm = INT_MAX;
        
        for (int& x : nums) {
            cnt[x]++;
            minm = min(minm, abs(x));
        }
        
        for (int i = -100; i < 0; ++i) {
            while (cnt[i] > 0 && k > 0) {
                cnt[i] --;
                cnt[-i] ++;
                k --;
            }
        }
        
        for (int i = -100; i <= 100; ++i)
            res += i * cnt[i];
        
        if (k % 2)
            res -= 2 * minm;
        
        return res;
    }
};