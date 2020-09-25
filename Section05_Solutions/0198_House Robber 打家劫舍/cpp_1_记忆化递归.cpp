/// 198. House Robber [9-4 状态的定义和状态转移 House Robber.mp4]
/// https://leetcode.com/problems/house-robber/description/
/// 记忆化搜索
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

private:
    // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益
    vector<int> memo;

    // 考虑抢劫nums[index...nums.size())这个范围的所有房子
    int tryRob(const vector<int> &nums, int index){

        if(index >= nums.size())
            return 0;

        if(memo[index] != -1)
            return memo[index];

        int res = 0;
        for(int i = index ; i < nums.size() ; i ++)
            res = max(res, nums[i] + tryRob(nums, i + 2));
        memo[index] = res;
        return res;
    }

public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return tryRob(nums, 0);
    }
};

int main() {

    int nums[] = {2, 1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;

    return 0;
}