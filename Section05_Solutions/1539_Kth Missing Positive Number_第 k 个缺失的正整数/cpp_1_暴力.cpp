class Solution {
public:
    const int N = 2010;
    int findKthPositive(vector<int>& arr, int k) {
        int res = 0;
        vector<int> nums(N, 0);
        for (int i = 1; i < N; i++) nums[i] = i;
        for (int& x : arr) nums[x] = -1;
        for (int i = 1; i < N; i++) {
            if (nums[i] == -1) continue;
            else k--;
            if (k == 0) return nums[i];
        }
        return -1;
    }
};