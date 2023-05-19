// 左端点为 j 右端点为 i 的写法
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        using LL = long long;
        int n = nums.size(), res = 0;
        vector<LL> s(n + 1);
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= n; i++)
            s[i] = s[i-1] + nums[i-1];
        for (int i = 1, j = 1; i <= n; i++) {
            while ((LL)(i - j + 1) * nums[i-1] - (s[i] - s[j-1]) > k) j++;
            res = max(res, i - j + 1);
        }
        return res;
    }
};

// --------------------------------------------------------
// 左端点为 i 右端点为 j 的写法

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        using LL = long long;
        int n = nums.size(), res = 0;
        vector<LL> s(n + 1);
        sort(nums.begin(), nums.end());
        for (int j = 1; j <= n; j++)
            s[j] = s[j-1] + nums[j-1];
        for (int i = 1, j = 1; j <= n; j++) {
            while ((LL)(j - i + 1) * nums[j-1] - (s[j] - s[i-1]) > k) i++;
            res = max(res, j - i + 1);
        }
        return res;
    }
};
