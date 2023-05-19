#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size()-1; i <= k;) {
            if (nums[i] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[i] == 2)
                swap(nums[i], nums[k--]);
            else i++;
        }
    }
};

int main() {
    return 0;
}
// 时间复杂度：O(n)
// 空间复杂度：O(1)
// 遍历数组一遍