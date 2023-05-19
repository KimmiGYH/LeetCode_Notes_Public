class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, fast = 1;
        int previous = nums[0];
        while (fast < nums.size()) {
            if (nums[fast] != previous) {
                previous = nums[fast];
                swap(nums[slow++], nums[fast++]);//用了swap其实没必要反倒添了麻烦
            }
            else
                fast++;
        }
        return slow;
    }
};