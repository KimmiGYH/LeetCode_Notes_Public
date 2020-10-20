#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < j; i++) {
            while (i < j && numbers[i] + numbers[j] > target)
                j--;
            if (i < j && numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
        }
        return {};
    }
};
// Time: O(n) 其中 n 是数组的长度。两个指针移动的总次数最多为 n 次。
// Space: O(1)