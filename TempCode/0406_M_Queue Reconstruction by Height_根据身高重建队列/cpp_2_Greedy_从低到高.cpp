#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int n = people.size();
        vector<vector<int>> res(n);
        for (const vector<int>& p : people) {
            int spaces = p[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (res[i].empty()) {
                    -- spaces;
                    if (!spaces) {
                        res[i] = p;
                        break;
                    }
                }
            }
        }
        return res;
    }
};