class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> cnt;
        cnt[0]++; //最开始S[0]在里面，所以将0插入
        for (int i = 1, sum = 0; i <= n; i++) { //sum表示当前的前缀和
            sum += nums[i-1];
            res += cnt[sum - goal];
            cnt[sum]++;
        }
        return res;
    }
};
// ------------------------------------------------------
// 写法二：for range 范围for
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, res = 0;
        unordered_map<int, int> cnt;
        cnt[0]++;
        for (int& num : nums) {
            sum += num;
            res += cnt[sum - goal];
            cnt[sum]++;
        }
        return res;
    }
};