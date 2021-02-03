#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        // citations = [3,0,6,1,5]
        // 从小到大排序  [0,1,3,5,6] size=5
        sort(c.begin(), c.end());
        int res = 0, h = c.size();
        for (int i = 0; i < h; i++) {
            if (c[i] >= h - i) {
                res = h - i;
                break;
            }
        }
        return res;
    }
};