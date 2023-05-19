#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st(begin(arr), end(arr));
        for (int i = 1; i <= arr.back(); ++i) {
            if (!st.count(i)) --k;
            if (k == 0) return i;
        }
        return arr.size() + k;
    }
};