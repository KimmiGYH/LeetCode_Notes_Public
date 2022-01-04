class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr(nums);
        sort(arr.begin(), arr.end());
        int i = 0, j = nums.size() - 1;
        while (i <= j && nums[i] == arr[i]) i++;
        while (i <= j && nums[j] == arr[j]) j--;
        return j - i + 1;
    }
};