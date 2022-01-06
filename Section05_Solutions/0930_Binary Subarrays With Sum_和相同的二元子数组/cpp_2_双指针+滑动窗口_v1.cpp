class Solution {
public:
    /**Ex:
    index   0,1,2,3,4
    nums = [1,0,1,0,1], goal = 2
    sum  = [1,1,2,2,3]
    */
    int atMost(vector<int>& nums, int goal) {
        int n = nums.size(), cnt = 0;
        if (goal < 0) return 0;
        for (int i = 0, j = 0, sum = 0; j < n; j++) {
            sum += nums[j];
            while (sum > goal) {
                sum -= nums[i];
                i++;
            }
            cnt += j - i + 1;
            //goal=2: cnt = 1 2 3 4  4
            //              1 3 6 10 14
            //goal=1: cnt = 1 2 2 3  2
            //              1 3 5 8  10 
        }
        return cnt;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

/*
Subarrays with sum at most 2 are are like : [1] , [0] , [1,0] , [1,0,1] ...
Subarrays with sum at most 1 are like : [1] , [0], [1,0] ... -> if we filter these subarrays from the bigger list, we we will be left with is only those subarrays with sum=2
*/