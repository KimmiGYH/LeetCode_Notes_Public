#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int quick_sort(vector<int>& nums, int l, int r, int p) {

        if (l == r) return nums[l];

        int i = l - 1, j = r + 1, x = nums[l + r >> 1];
        while (i < j) {
            // 因为求的是第k大个元素，而不是第k小个元素，所以这里符号要翻转一下
            do i++; while (nums[i] > x);
            do j--; while (nums[j] < x);
            // while (nums[++i] > x);
            // while (nums[--j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (p <= j) return quick_sort(nums, l, j, p);
        else return quick_sort(nums, j+1, r, p);
    }


    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k - 1);
    }
};

int main()
{
    vector<int> vec = {3,2,1,5,6,4,15,9,11};
    int k = 2;
    Solution().findKthLargest(vec, k);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    cout << vec[k-1];

    return 0;
}

/*
Input:
[3,2,1,5,6,4,15,9,11] and k = 2

Output:
15 11 9 6 5 4 1 2 3 
11
*/