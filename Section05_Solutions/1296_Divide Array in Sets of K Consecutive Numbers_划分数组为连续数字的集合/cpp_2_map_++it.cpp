#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k)  return false;
        map<int, int> m; // BST
        for (int& c : nums) ++m[c];//花费 O(nlogn)
        // --- 花费 O(n) ---
        while (m.size()) {
            auto it = m.begin(); //O(1)
            const int x = it->first;
            for (int i = 0; i < k; ++i) {
                if (it->first != x + i) return false;
                if (--it->second == 0) m.erase(it);
                ++it; //O(1)
            }
        }
        return true;
    }
};