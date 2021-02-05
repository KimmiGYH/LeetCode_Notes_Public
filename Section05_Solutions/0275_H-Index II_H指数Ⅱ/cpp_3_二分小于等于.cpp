#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (c[mid] == n - mid) return c[mid]; //类似写法二
            if (c[mid] > n - mid) r = mid - 1;
            else l = mid + 1;
        }
        return n - l;
    }
};