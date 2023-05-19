class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; //一开始就判断 k
        int res = 0, product = 1;
        for (int i = 0, j = 0; i < nums.size(); i ++) {
            product *= nums[i];
            while (product >= k)
                product /= nums[j ++];
            res += i - j + 1;
        }
        return res;
    }
};

// ---------------------------------------------

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // if (k <= 1) return 0;
        int res = 0, product = 1;
        for (int i = 0, j = 0; i < nums.size(); i ++) {
            product *= nums[i];
            while (j <= i && product >= k) //如果一开始不判断K，则需要在此加条件 j <= i
                product /= nums[j ++];
            res += i - j + 1;
        }
        return res;
    }
};