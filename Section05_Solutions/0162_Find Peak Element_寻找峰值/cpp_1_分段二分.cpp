#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};
/*nums[mid+1] 中 mid+1 是不会越界的。
反证法：假设会越界，mid+1=nums.size()，则 mid=nums.size()-1
因为 r=nums.size()-1，且 mid 取值是下取整，所以要使得 mid=nums.size()-1，则必须要让 l 也等于 nums.size()-1
但 l==r 时不会进入循环，所以 mid+1 不会越界。
 */