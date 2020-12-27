#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1000)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(1001);
        for (auto trip : trips) {
            passengers[trip[1]] += trip[0];
            passengers[trip[2]] -= trip[0];            
        }
        int cnt = 0;
        for (int p : passengers) {
            cnt += p;
            if (cnt > capacity) return false;
        }
        return true;
    }
};