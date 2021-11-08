#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        while (l < r) {
            int mid = l + r >> 1;
            if (get(quantities, mid) <= n) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    int get(vector<int>& quantities, int x) { // x是每次分配给一家商店最大的货物数量
        int total = 0;
        for (auto q : quantities) {
            total += (q + x - 1) / x;//上取整技巧
        }
        return total;
    }    
};