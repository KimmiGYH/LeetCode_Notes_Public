#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> cur;
        for (int i = 0; i < n + 1; ++i) {
            vector<int> prev = cur;
            for (int j = 1; j < i; ++j) {
                cur[j] = prev[j - 1] + prev[j];
            }
            cur.push_back(1);
        }
        return cur;
    }
};