#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        // citations = [3,0,6,1,5]
        // 排序后       [6,5,3,1,0] size=5
        sort(c.begin(), c.end(), greater<int>()); // 从大到小排
        for (int h = c.size(); h; h--)
            if (c[h - 1] >= h)
                return h;
        return 0;            
    }
};