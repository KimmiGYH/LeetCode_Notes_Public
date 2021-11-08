#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        while(l < r) {
            int mid = l + r >> 1, total = 0;
            // for (int q : quantities) {
            //     if (q % mid == 0) total += q/mid;
            //     else total += q/mid + 1;
            // }
            for (int q : quantities)
                total += (q + mid - 1) / mid;
            if (total <= n) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
