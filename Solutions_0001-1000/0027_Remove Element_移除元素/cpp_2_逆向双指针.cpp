class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                j --;
            } else
                i ++;
        }
        return i;
    }
};

// ---------- 相同方法，另一种写法 2023年5月16日 -----------

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] != val)
                l++;
            else
                swap(nums[l], nums[r--]);
        }
        return l;
    }
};