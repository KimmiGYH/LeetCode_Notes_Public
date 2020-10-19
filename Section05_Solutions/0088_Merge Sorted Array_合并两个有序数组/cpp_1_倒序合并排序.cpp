#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int k = n + m - 1;
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0)
            if (nums1[i] >= nums2[j])   nums1[k--] = nums1[i--];
            else                        nums1[k--] = nums2[j--];
        // 如果 num2 比 nums1 长，那么将 nums2 中的元素拷贝到 nums1 的位置上。
        // 如果 nums1 比 nums2 长，那么 nums1 中的元素就已经在正确的位置上了。
        while (j >= 0)                  nums1[k--] = nums2[j--];
    }
};