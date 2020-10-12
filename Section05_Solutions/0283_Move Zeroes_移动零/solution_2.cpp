#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int k = 0;

        // for (int i = 0; i < nums.size(); i++)
        //     if (nums[i])
        //         nums[k++] = nums[i];

        for (auto x : nums)
            if (x)
                nums[k++] = x;
        
        // for (int i = k; i < nums.size(); i++)
        //     nums[i] = 0;

        while (k < nums.size())
            nums[k++] = 0;
    }
};

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    Solution().moveZeroes(vec);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
        
    return 0;
}

// Time: O(n); Space: O(1)
// 1 3 12 0 0 