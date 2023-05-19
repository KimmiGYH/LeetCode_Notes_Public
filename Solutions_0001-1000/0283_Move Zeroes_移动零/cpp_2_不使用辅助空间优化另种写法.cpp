// 时间复杂度: O(n)
// 空间复杂度: O(1)
// 原地算法，未使用辅助空间

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (auto x : nums)
            if (x)
                nums[k++] = x;
        while (k < nums.size())
            nums[k++] = 0;

    }
};

int main() {

    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    Solution().moveZeroes(vec);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}
// 1 3 12 0 0 