#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int l = 0, r = n; 
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (c[n - mid] >= mid) l = mid; //逆序
            else r = mid - 1;
        }
        return r;
    }
};
/*坐标变换：从大到小数第 mid 个数
n-1 是第 1 个数
所以第 mid 个数是 n-mid
*/