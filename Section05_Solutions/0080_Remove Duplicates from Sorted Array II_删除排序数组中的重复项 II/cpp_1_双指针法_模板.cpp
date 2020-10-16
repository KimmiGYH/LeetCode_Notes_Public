#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 0;
        for (auto x : nums)
            if (k < 2 || nums[k-2] != x)
                nums[k++] = x;

        return k;
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