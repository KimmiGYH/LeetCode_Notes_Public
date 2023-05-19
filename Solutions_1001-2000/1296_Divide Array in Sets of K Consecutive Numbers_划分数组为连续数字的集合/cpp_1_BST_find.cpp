#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k)  return false;
        map<int, int> m; // BST,
        for (int& c : nums) ++m[c]; //花费 O(nlogn)
        // --- 花费 O(nlogn) ---
        while (m.size()) {
            const int x = m.cbegin()->first;
            for (int i = 0; i < k; ++i) {
                auto it = m.find(x + i); //logn
                if (it == m.cend()) return false;
                if (--it->second == 0) m.erase(it);
            }
        }
        // ------------------
        return true;
    }
};