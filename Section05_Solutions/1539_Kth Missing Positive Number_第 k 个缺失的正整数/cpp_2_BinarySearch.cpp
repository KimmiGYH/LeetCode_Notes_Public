#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int m = left + right >> 1;
            if (arr[m] - (m + 1) >= k)
                right = m - 1;
            else
                left = m + 1;
        }
        return left + k;
    }
};