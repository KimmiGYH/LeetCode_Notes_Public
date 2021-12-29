#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (idx < 1 || nums[idx-1] != nums[i])
                nums[idx++] = nums[i];
        }
        return idx;
    }
};

int main()
{
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    int len = Solution().removeDuplicates(vec);
    for (int i = 0; i < len; i++)
        cout << vec[i] << " ";
    cout << endl;        
    return 0;
}

// 0 1 2 3 4
// Time: O(n); Space: O(1)