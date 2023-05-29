class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0; // i: fast, j: slow
        for (i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};

// ------------------------------

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int x : nums) {
            if (x != 0)
                nums[idx++] = x;
        }
        while (idx < nums.size()) {
            nums[idx++] = 0;
        }
    }
};