// case 1: arr: [1, 2, 3], k = 2, result = 5; return len + k;
// case 2: arr: [3, 4, 5], k = 2, result = 2; return k;
// case 3: arr: [3, 4, 5, 9], k = 3, result = 6

#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int len = arr.size();

        if(arr[0] - 1 >= k)
            return k;
        for(int i = 0; i < len; ++i) {
            if(arr[i] - i - 1 >= k) // 缺了 arr[i]-(i+1) 个数
                return i + k;
        }
        return len + k;
    }
};