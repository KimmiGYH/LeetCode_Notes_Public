#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> hash;
        for (int card : deck) ++hash[card];
        int mn = INT_MAX;
        for (auto &cnt : hash)
            mn = min(mn, cnt.second);
        if (mn < 2) return false;
        for (int i = 2; i <= mn; ++i) {
            bool valid = true;
            for (auto &cnt : hash) {
                if (cnt.second % i != 0) {
                    valid = false;
                    break;
                }
            }
            if (valid)  return true;
        }
        return false;
    }
};