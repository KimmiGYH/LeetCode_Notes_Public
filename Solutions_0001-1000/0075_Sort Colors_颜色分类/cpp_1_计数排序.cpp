#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count[3] = {0}; // 存放0,1,2三个元素的频率
        for (int i = 0; i < nums.size(); i++) {
            assert( nums[i] >= 0 && nums[i] <= 2 ); // 错误处理，防止数组越界
            count[nums[i]] ++;
        }
        
        int index = 0;
        for (int i = 0; i < count[0]; i++)
            nums[index++] = 0;
        for (int i = 0; i < count[1]; i++)
            nums[index++] = 1;
        for (int i = 0; i < count[2]; i++)
            nums[index++] = 2;
    }
};

int main() {
    return 0;
}
// 时间复杂度：O(n)
// 空间复杂度：O(k)，k 为元素的取值范围