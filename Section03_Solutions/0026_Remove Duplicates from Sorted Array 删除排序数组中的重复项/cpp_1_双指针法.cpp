// 26_Remove Duplicates from Sorted Array / Solution 1
// Two pointers 双指针法 / C++
// Time Complexity: O(n)
// Space Complexity: O(1)
// 注意题目中：不要使用额外的数组空间，必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // 别忘记空数组的判断

        int index;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1; // 别忘了index 是从0开始的，所以返回 index + 1
    }
};