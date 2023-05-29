class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0)
                swap(nums[slow++], nums[fast]);
        }
    }
};

// ------------------------

class Solution {
public:
    void moveZeroes(vector<int>& nums) { //这种写法错误，因为 x 是把 nums[i] 存下来，而不是
        int idx = 0;
        for (int x : nums) {
            if (x != 0)
                swap(nums[idx++], x);
        }
    }
};